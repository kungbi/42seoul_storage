#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iterator>

class Span {
private:
	std::vector<int> numbers;
	const unsigned int maxSize;

	void validate(void);

	Span(void);
public:
	Span(unsigned int N);
	Span &operator=(const Span& span);
	~Span(void);

	void addNumber(int number);

	template <typename T>
	void addNumbers(T begin, T end) {
		if (numbers.size() + std::distance(begin, end) > maxSize)
			throw FullSpanException();
		numbers.insert(numbers.end(), begin, end);
	}

	int shortestSpan(void);
	int longestSpan(void);

	class FullSpanException: public std::exception {
		virtual const char* what() const throw();
	};
};

#endif