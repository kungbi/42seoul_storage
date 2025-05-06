// PmergeMe.cpp
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::handleError(const std::string &msg) {
    std::cerr << msg << std::endl;
    std::exit(1);
}

void PmergeMe::parseInput(int argc, char **argv) {
    if (argc < 2)
        handleError("Error: Not enough arguments");

    for (int i = 1; i < argc; ++i) {
        long num = std::atol(argv[i]);
        if (num < 0)
            handleError("Error: Negative number not allowed");
        else if (num == 0)
            handleError("Error: Invalid argument (0 or non-numeric)");
        else if (num > INT_MAX)
            handleError("Error: Number too large");

        vectorData.push_back(static_cast<int>(num));
        listData.push_back(static_cast<int>(num));
    }
}

void PmergeMe::generateJacobsthal(int size) {
    jacobsthalSeq.clear();
    if (size <= 0)
        return;

    unsigned int a = 0, b = 1;
    jacobsthalSeq.push_back(b);
    while (b < static_cast<unsigned int>(size)) {
        unsigned int c = b * 2 + a;
        jacobsthalSeq.push_back(c);
        a = b;
        b = c;
    }
}

void PmergeMe::run(int argc, char **argv) {
    parseInput(argc, argv);

    std::cout << "Before (vector): ";
    showContainer(vectorData, "");

    clock_t start = clock();
    runSort(vectorData, sortedVector);
    clock_t end = clock();
    double vectorTime1 = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "After (vector): ";
    showContainer(sortedVector, "");

	
    std::cout << "Before (list): ";
    showContainer(listData, "");
	
    start = clock();
    runSort(listData, sortedList);
    end = clock();
    double vectorTime2 = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	
    std::cout << "Time to process a range of " << vectorData.size()
              << " elements with std::vector<int> : " << std::fixed << std::setprecision(6)
              << vectorTime1 << " s\n";

    std::cout << "Time to process a range of " << listData.size()
              << " elements with std::list<int> : " << std::fixed << std::setprecision(6)
              << vectorTime2 << " s\n";

    if (!isSorted(sortedVector))
        std::cerr << "Vector is not sorted correctly!" << std::endl;
    if (!isSorted(sortedList))
        std::cerr << "List is not sorted correctly!" << std::endl;
}
