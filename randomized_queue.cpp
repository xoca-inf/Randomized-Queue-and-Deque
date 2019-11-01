//
// Created by tima on 31.05.2019.
//

#include "randomized_queue.hpp"

template<class T>
randomized_queue<T>::iterator::iterator(const randomized_queue::iterator &other_iterator) :
m_BEGIN(other_iterator.m_BEGIN),
m_SIZE(other_iterator.m_SIZE),
m_permutation(std::move(other_iterator.m_permutation)),
m_INDEX(other_iterator.m_INDEX){}

template<class T>
typename randomized_queue<T>::iterator &randomized_queue<T>::iterator::operator=(const randomized_queue::iterator &other_iterator) {
    m_BEGIN = other_iterator.m_BEGIN;
    m_SIZE = other_iterator.m_SIZE;
    m_permutation = other_iterator.m_permutation;
    m_INDEX = other_iterator.m_INDEX;
}

template<class T>
void randomized_queue<T>::iterator::generate() {
    m_permutation.resize(m_SIZE);
    for (int i = 0; i < m_SIZE; ++i) {
        m_permutation[i] = i;
    }
    std::shuffle(m_permutation.begin(), m_permutation.end(), std::mt19937_64(std::random_device()()));
    m_permutation.push_back(m_SIZE);
}

template<class T>
typename randomized_queue<T>::iterator randomized_queue<T>::iterator::operator--(int) {
    iterator iterator1(*this);
    m_INDEX--;
    return iterator1;
}

template<class T>
typename randomized_queue<T>::iterator &randomized_queue<T>::iterator::operator--() {
    --m_INDEX;
    return* this;
}

template<class T>
typename randomized_queue<T>::iterator &randomized_queue<T>::iterator::operator++() {
    ++m_INDEX;
    return* this;
}

template<class T>
typename randomized_queue<T>::iterator randomized_queue<T>::iterator::operator++(int) {
    iterator iterator1(*this);
    m_INDEX++;
    return iterator1;
}

template<class T>
T &randomized_queue<T>::iterator::operator*() {
    return *(m_BEGIN + m_permutation[m_INDEX]);
}

template<class T>
randomized_queue<T>::iterator::iterator(typename std::vector<T>::iterator begin, size_t size,bool is_end) : m_BEGIN(begin), m_SIZE(size){
    generate();
    if (is_end) {
        m_INDEX = m_SIZE;
    } else {
        m_INDEX = 0;
    }
}

template<class T>
bool randomized_queue<T>::iterator::operator==(const randomized_queue::iterator &rhs) const {
    return ((m_BEGIN + m_permutation[m_INDEX]) == (rhs.m_BEGIN + rhs.m_permutation[rhs.m_INDEX]));
}

template<class T>
bool randomized_queue<T>::iterator::operator!=(const randomized_queue::iterator &rhs) const {
    return !(rhs == *this);
}

template<class T>
size_t randomized_queue<T>::size() const {
    return m_data.size();
}

template<class T>
void randomized_queue<T>::enqueue(const T &new_element) {
    m_data.push_back(new_element);
    distribution();
}

template<class T>
T randomized_queue<T>::dequeue() {
    int position = m_distribution(m_mt19937_64);
    T removed_element = m_data[position];
    std::swap(m_data[position], m_data.back());
    m_data.pop_back();
    distribution();
    return removed_element;
}

template<class T>
T randomized_queue<T>::sample() {
    if (empty()) {
        throw std::runtime_error("Sample from empty queue");
    }
    unsigned position = m_distribution(m_mt19937_64);
    return m_data[position];
}

template<class T>
bool randomized_queue<T>::empty() const{
    return (size() == 0);
}

template<class T>
void randomized_queue<T>::distribution() {
    m_distribution = std::uniform_int_distribution<unsigned>(0, size() - 1);
}

template<class T>
std::mt19937_64 randomized_queue<T>::generation() {
    std::random_device randomDevice;
    return std::mt19937_64(randomDevice());
}

template<class T>
typename randomized_queue<T>::iterator randomized_queue<T>::end() {
    iterator iterator(m_data.begin(), size(), true);
    return iterator;
}

template<class T>
typename randomized_queue<T>::iterator randomized_queue<T>::begin() {
    iterator iterator(m_data.begin(), size(), false);
    return iterator;
}