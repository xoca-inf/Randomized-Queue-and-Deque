//
// Created by tima on 30.05.2019.
//

#ifndef QUEUE_HW2_DEQUE_H
#define QUEUE_HW2_DEQUE_H

#include <list>
#include <cstddef>
#include <stdexcept>

template <class T>
class Deque{
public:
    Deque() = default;
    ~Deque() = default;

    bool empty();

    unsigned int size() const;

    auto begin();
    auto end();

    void push_front(const T& new_element);
    void push_back(const T& new_element);

    const T& front() const;
    const T& back() const;

    void pop_front();
    void pop_back();
private:
    std::list<T> m_list;
};

#endif //QUEUE_HW2_DEQUE_H
