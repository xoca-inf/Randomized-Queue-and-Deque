//
// Created by tima on 31.05.2019.
//

#ifndef QUEUE_HW2_RANDOMIZED_QUEUE_HPP
#define QUEUE_HW2_RANDOMIZED_QUEUE_HPP

#include <vector>
#include <random>
#include <algorithm>
#include <stdexcept>

template <class T>
class randomized_queue {
public:
    randomized_queue() = default;
    ~randomized_queue() = default;

    size_t size() const;

    void enqueue(const T &new_element);

    T dequeue();
    T sample();

    bool empty() const;

    class iterator;
    class iterator {
        friend randomized_queue;
    public:
        iterator() = default;
        iterator(const iterator& other_iterator);
        ~iterator() = default;

        iterator& operator=(const iterator& other_iterator);
        iterator operator--(int);
        iterator& operator--();
        iterator& operator++();
        iterator  operator++(int);

        T& operator*();

        bool operator==(const iterator &rhs) const;
        bool operator!=(const iterator &rhs) const;
    private:
        iterator(typename std::vector<T>::iterator begin, size_t size, bool is_end);
        size_t m_SIZE = 0;
        size_t m_INDEX = 0;
        typename std::vector<T>::iterator m_BEGIN;
        std::vector<unsigned> m_permutation;
        void generate();
    };
    iterator end();
    iterator begin();
private:
    std::vector<T> m_data;
    std::uniform_int_distribution<unsigned> m_distribution;
    void distribution();
    std::mt19937_64 generation();
    std::mt19937_64 m_mt19937_64 = generation();
};

#endif //QUEUE_HW2_RANDOMIZED_QUEUE_HPP
