#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	
	char upperChar;
	for (int i = 1; i < argc; i++)
	{
		for(int j = 0; argv[i][j]; j++)
		{
			upperChar = std::toupper(argv[i][j]);
			std::cout << upperChar;
		}
	}
	std::cout << "\n";
}
