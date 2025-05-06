CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = main.cpp BitcoinExchange.cpp
OBJ = $(SRC:.cpp=.o)

NAME = btc

%.o : %.cpp $(INCLUDE)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all : $(NAME)

$(NAME) : $(OBJ) $(INCLUDE)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
