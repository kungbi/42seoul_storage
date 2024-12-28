CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Animal.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Cat.cpp Brain.cpp
OBJ = $(SRC:.cpp=.o)

NAME = ex02

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
