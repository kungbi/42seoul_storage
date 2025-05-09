// PmergeMe.hpp
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <utility>

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

// Template implementations

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
void PmergeMe::binaryInsertSorted(T &container, typename T::value_type value) {
    typename T::iterator it = container.begin();
    while (it != container.end() && *it < value) {
        ++it;
    }
    container.insert(it, value);
}

template <typename T>
void PmergeMe::pairAndSort(T &container, T &result) {
    std::vector<std::pair<int, int> > pairs;
    typename T::iterator it = container.begin();
    
    // 1. 짝짓기 (큰 값, 작은 값)으로 저장
    while (it != container.end()) {
        int first = *it;
        ++it;
        int second = (it != container.end()) ? *it : -1;
        if (second != -1 && first < second)
            pairs.push_back(std::make_pair(second, first));
        else
            pairs.push_back(std::make_pair(first, second));
        if (it != container.end()) ++it;
    }

    // 2. 큰 값 기준 정렬
    std::sort(pairs.begin(), pairs.end());

    // 3. 큰 값들로 초기 정렬 리스트 생성
    for (size_t i = 0; i < pairs.size(); ++i) {
        result.push_back(pairs[i].first);
    }

    // 🔥 4. Jacobsthal 수열 생성 (삽입할 작은 값 수만큼)
    generateJacobsthal(pairs.size());

    // 5. 작은 값들을 Jacobsthal 순서로 이진 삽입
    std::vector<bool> inserted(pairs.size(), false); // 중복 삽입 방지
    for (size_t i = 0; i < jacobsthalSeq.size(); ++i) {
        size_t idx = jacobsthalSeq[i];
        if (idx >= pairs.size() || inserted[idx] || pairs[idx].second == -1)
            continue;
        binaryInsertSorted(result, pairs[idx].second);
        inserted[idx] = true;
    }

    // 6. Jacobsthal 수열 외의 남은 인덱스들 삽입
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
