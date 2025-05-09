#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <cstdlib>
# include <climits>
# include <ctime>
# include <iomanip>
# include <algorithm>
# include <utility>

class PmergeMe {
private:
    std::vector<int> vectorData;
    std::list<int> listData;
    std::vector<int> sortedVector;
    std::list<int> sortedList;
    std::vector<unsigned int> jacobsthalSeq;

    void parseInput(int argc, char **argv);
    void generateJacobsthal(int size);

    template <typename T>
    void runSort(T &container, T &sorted);

    template <typename T>
    void pairAndSort(T &container, T &result);

    template <typename T>
    void binaryInsertSorted(T &container, typename T::value_type value);

    template <typename T>
    bool isSorted(const T &container);

    template <typename T>
    void showContainer(const T &container, const std::string &label);

    void handleError(const std::string &msg);

public:
    PmergeMe();
    ~PmergeMe();
    void run(int argc, char **argv);
};


template <typename T>
void PmergeMe::showContainer(const T &container, const std::string &label) {
    std::cout << label;
    typename T::const_iterator it = container.begin();
    while (it != container.end()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

template <typename T>
bool PmergeMe::isSorted(const T &container) {
    if (container.empty()) return true;
    typename T::const_iterator prev = container.begin();
    typename T::const_iterator curr = prev;
    ++curr;
    while (curr != container.end()) {
        if (*prev > *curr) return false;
        ++prev;
        ++curr;
    }
    return true;
}

template <typename T>
void PmergeMe::binaryInsertSorted(T &, typename T::value_type) {
    static_assert(sizeof(T) == -1, "binaryInsertSorted is not supported for this container type.");
}

template <>
inline void PmergeMe::binaryInsertSorted(std::vector<int> &container, int value) {
    std::vector<int>::iterator it = std::lower_bound(container.begin(), container.end(), value);
    container.insert(it, value);
}

template <>
inline void PmergeMe::binaryInsertSorted(std::list<int> &container, int value) {
    std::list<int>::iterator it = container.begin();
    while (it != container.end() && *it < value)
        ++it;
    container.insert(it, value);
}




template <typename T>
void PmergeMe::pairAndSort(T &container, T &result) {
    std::vector<std::pair<int, int> > pairs;
    typename T::iterator it = container.begin();
    
    while (it != container.end()) {
        int first = *it;
        ++it;
        
        int second = -1;
        if (it != container.end()) {
            second = *it;
            ++it;
        }

        if (second != -1 && first < second)
            pairs.push_back(std::make_pair(second, first));
        else
            pairs.push_back(std::make_pair(first, second));
    }

    std::sort(pairs.begin(), pairs.end());
    for (size_t i = 0; i < pairs.size(); ++i) {
        result.push_back(pairs[i].first);
    }

    generateJacobsthal(pairs.size());

    std::vector<bool> inserted(pairs.size(), false); // 중복 삽입 방지
    for (size_t i = 0; i < jacobsthalSeq.size(); ++i) {
        size_t idx = jacobsthalSeq[i];
        if (pairs.size() <= idx || inserted[idx] || pairs[idx].second == -1)
            continue;
        binaryInsertSorted(result, pairs[idx].second);
        inserted[idx] = true;
    }

    for (size_t i = 0; i < pairs.size(); ++i) {
        if (!inserted[i] && pairs[i].second != -1)
            binaryInsertSorted(result, pairs[i].second);
    }
}


template <typename T>
void PmergeMe::runSort(T &container, T &sorted) {
    if (container.size() <= 1) {
        sorted = container;
        return;
    }
    pairAndSort(container, sorted);
}

#endif
