//
// Created by tima on 30.05.2019.
//

#include "Deque.hpp"

template<class T>
bool Deque<T>::empty() {
    return m_list.empty();
}

template<class T>
unsigned int Deque<T>::size() const {
    return m_list.size();
}

template<class T>
auto Deque<T>::begin() {
    return m_list.begin();
}

template<class T>
auto Deque<T>::end() {
    return m_list.end();
}

template<class T>
void Deque<T>::push_front(const T &new_element) {
    m_list.push_front(new_element);
}

template<class T>
void Deque<T>::push_back(const T &new_element) {
    m_list.push_back(new_element);
}

template<class T>
const T &Deque<T>::front() const {
    return m_list.front();
}

template<class T>
const T &Deque<T>::back() const {
    return m_list.back();
}

template<class T>
void Deque<T>::pop_front() {
    m_list.pop_front();
}

template<class T>
void Deque<T>::pop_back() {
    m_list.pop_back();
}
