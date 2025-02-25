#include "Span.hpp"

Span::Span(unsigned int N) : maxSize(N) {}

Span::~Span(void) {}

Span &Span::operator=(const Span &span) {
	(void)span;
	return *this;
}

void Span::addNumber(int number) {
	if (numbers.size() >= maxSize)
		throw FullSpanException();
	numbers.push_back(number);
}

void Span::validate(void) {
	if (numbers.size() < 2)
		throw FullSpanException();
}

int Span::shortestSpan(void) {
	validate();

	std::vector<int> sorted(numbers);
	std::sort(sorted.begin(), sorted.end());
	int min = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++) {
		int diff = sorted[i] - sorted[i - 1];
		if (diff < min)
			min = diff;
	}
	return min;
}

int Span::longestSpan(void) {
	validate();

	std::vector<int> sorted(numbers);
	std::sort(sorted.begin(), sorted.end());
	return sorted.back() - sorted.front();
}

const char *Span::FullSpanException::what() const throw() {
	return "Span is full";
}