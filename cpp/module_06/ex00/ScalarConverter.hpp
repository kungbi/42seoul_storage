#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter {
private:
	ScalarConverter(void);
	ScalarConverter& operator=(ScalarConverter const &scalarConverter);
	ScalarConverter(ScalarConverter const &scalarConverter);
	~ScalarConverter(void);

public:

	static void convert(const std::string& str);
};

#endif