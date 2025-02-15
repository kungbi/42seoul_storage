#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/select.h>	
#include <unistd.h>
#include <iostream>


class FdSet {
private:
	fd_set fdSet;
public:
	FdSet() {
		FD_ZERO(&this->fdSet);
	}

	void addFd(int fd) {
		std::cout << "Adding fd: " << fd << " to fdSet" << std::endl;
		FD_SET(fd, &this->fdSet);
	}

	void removeFd(int fd) {
		std::cout << "Removing fd: " << fd << " from fdSet" << std::endl;
		FD_CLR(fd, &this->fdSet);
	}

	fd_set* getFdSet() {
		return &this->fdSet;
	}

	bool exist(int fd) {
		return FD_ISSET(fd, &this->fdSet);
	}
};

enum SocketResponseType {
	READ,
	WRITE
};

static const int BUFFER_SIZE = 1024;

class SocketResponse {
private:
	const int fd;
	const SocketResponseType type;
	const char *buffer;
	const int size;
public:
	SocketResponse(int fd, SocketResponseType type, const char *buffer)
		: fd(fd), type(type), buffer(buffer), size(buffer ? strlen(buffer) : 0) {
	}

	~SocketResponse() {
		if (buffer != nullptr) {
			free(const_cast<char*>(buffer));
		}
	}

	const char* getBuffer() const{
		return this->buffer;
	}

	int getSize() const {
		return this->size;
	}

	int getFd() const {
		return this->fd;
	}
};
std::ostream& operator<<(std::ostream &out, const SocketResponse &obj) {
	std::cout << "fd: " << obj.getFd() << " size: " << obj.getSize() << " buffer: " << (obj.getBuffer()? obj.getBuffer(): "") << std::endl;
	return out;
}

class FdSets {
private:
	FdSet readFdSet;
	FdSet writeFdSet;
	int maxFd;

	void updateMaxFd(int fd) {
		std::cout << "Updating maxFd with fd: " << fd << std::endl;
		if (this->maxFd < fd) {
			this->maxFd = fd;
			return;
		}
		if (this->maxFd == fd) {
			this->maxFd--;
			return;
		}
	}

	char* readBuffer(int fd) {
		std::cout << "Reading buffer from fd: " << fd << std::endl;
		char *buffer = (char*)malloc(BUFFER_SIZE);
		if (!buffer) {
			throw std::bad_alloc();
		}
		int n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0) {
			return nullptr;
		}
		buffer[n] = '\0';
		return buffer;
	}
public:
	FdSets() {
		maxFd = 0;
		FD_ZERO(this->readFdSet.getFdSet());
		FD_ZERO(this->writeFdSet.getFdSet());
	}

	int getMaxFd() {
		return this->maxFd;
	}

	void addReadFd(int fd) {
		this->readFdSet.addFd(fd);
		this->updateMaxFd(fd);
	}

	void addWriteFd(int fd) {
		this->writeFdSet.addFd(fd);
		this->updateMaxFd(fd);
	}

	void removeReadFd(int fd) {
		this->readFdSet.removeFd(fd);
		this->updateMaxFd(fd);
	}

	void removeWriteFd(int fd) {
		this->writeFdSet.removeFd(fd);
		this->updateMaxFd(fd);
	}

	SocketResponse nextSocketResponse() {
		std::cout << "Waiting for the next socket response..." << std::endl;
		fd_set readFds = *this->readFdSet.getFdSet();
		fd_set writeFds = *this->writeFdSet.getFdSet();

		if (select(this->getMaxFd() + 1, &readFds, &writeFds, NULL, NULL) == -1) {
			throw std::runtime_error("Select error");
		}

		std::cout << "Checking fd" << std::endl;
		for (int fd = 0; fd <= this->maxFd; fd++) {
			if (FD_ISSET(fd, &readFds)) {
				if (fd == 3) { // 서버 소켓 파일 디스크립터
					std::cout << "Accepting new connection on fd: " << fd << std::endl;
					int clientFd = accept(fd, NULL, NULL);
					if (clientFd < 0) {
						throw std::runtime_error("Accept error");
					}
					this->addReadFd(clientFd);
					std::cout << "New client connected with fd: " << clientFd << std::endl;
					return SocketResponse(fd, READ, this->readBuffer(fd));
				} else {
					std::cout << "Read event on fd: " << fd << std::endl;
					return SocketResponse(fd, READ, this->readBuffer(fd));
				}
			}
			if (FD_ISSET(fd, &writeFds)) {
				std::cout << "Write event on fd: " << fd << std::endl;
				return SocketResponse(fd, WRITE, this->readBuffer(fd));
			}
		}
		return SocketResponse(-1, READ, NULL);
	}
};

class Server {
private:
	FdSets fdSets;

	void initialize() {
		std::cout << "Initializing server..." << std::endl;
		int socketFd = socket(AF_INET, SOCK_STREAM, 0);
		std::cout << "Socket created with fd: " << socketFd << std::endl;
		int option_value = 1;
		setsockopt(socketFd, SOL_SOCKET, SO_REUSEADDR, &option_value, sizeof(int));
		std::cout << "Socket options set" << std::endl;

		sockaddr_in serverAddress;
		memset(&serverAddress, 0, sizeof(serverAddress));
		serverAddress.sin_family = AF_INET;
		serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
		serverAddress.sin_port = htons(8080);

		bind(socketFd, (struct sockaddr *) &serverAddress, sizeof(serverAddress));
		std::cout << "Socket bound to address" << std::endl;

		listen(socketFd, 100);
		std::cout << "Socket is listening" << std::endl;
		fcntl(socketFd, F_SETFL, O_NONBLOCK);

		this->fdSets.addReadFd(socketFd);

		std::cout << "Server is running on port 8080" << std::endl;
	}
public:
	Server() {
		this->initialize();
	}

	int run() {
		std::cout << "Server is running..." << std::endl;
		while (true) {
			SocketResponse response = this->fdSets.nextSocketResponse();
			std::cout << "Received response: " << response << std::endl;
		}
	}

	
};

int main() {
	std::cout << "Starting server..." << std::endl;
	Server server;
	return server.run();
}