#include <iostream>
#include <fstream>
#include <string>

void replaceAndWrite(std::ofstream &outfile, const std::string &line, const std::string &s1, const std::string &s2) {
    std::string modifiedLine;
    size_t start = 0;
    size_t pos;

    while ((pos = line.find(s1, start)) != std::string::npos) {
        modifiedLine.append(line, start, pos - start);
        modifiedLine.append(s2);
        start = pos + s1.length();
    }
    modifiedLine.append(line, start, line.length() - start);
    outfile << modifiedLine << '\n';
}

bool validateArguments(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Error: Expected 3 arguments but got " << argc - 1 << '\n';
        return false;
    }
    if (std::string(argv[1]).empty() || std::string(argv[2]).empty() || std::string(argv[3]).empty()) {
        std::cout << "Error: Arguments must not be empty\n";
        return false;
    }
    return true;
}

int main(int argc, char **argv) {
    if (!validateArguments(argc, argv))
        return 1;

    std::string inFileName = argv[1];
    std::string outFileName = inFileName + ".replace";
    std::string s1 = argv[2];
    std::string s2 = argv[3];


    std::ifstream infile(inFileName.c_str());
    if (!infile.is_open()) {
        std::cout << "Error: Could not open input file\n";
        return 1;
    }

    std::ofstream outfile(outFileName.c_str());
	if (!outfile.is_open()) {
		std::cout << "Error: Could not create output file\n";
		return 1;
	}

    std::string line;
    while (std::getline(infile, line)) {
        replaceAndWrite(outfile, line, s1, s2);
    }

    if (infile.bad()) {
        std::cout << "Error: Failed while reading the file\n";
        return 1;
    }

    std::cout << "File processed successfully. Output saved in: " << outFileName << '\n';
    return 0;
}
