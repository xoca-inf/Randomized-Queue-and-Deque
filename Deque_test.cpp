//
// Created by tima on 31.05.2019.
//

#include <iostream>
#include <deque>
#include "Deque.hpp"
#include "Deque.cpp"
#include <cstdio>
#include <assert.h>


template<class T>
void compare(T fir, T sec) {
    assert(fir == sec);
}

template<class T>
void test_methods(Deque<T> &d1, std::deque<T> &d2) {
    compare(d1.empty(), d2.empty());
    compare(d1.size(), d2.size());
}


void random_push_int(Deque<int> &d1, std::deque<int> &d2) {
    for (int i = 0; i < 100; i++) {
        if (i % 2 == 0) {
            d1.push_back(i);
            d2.push_back(i);
        } else {
            d1.push_front(i);
            d2.push_front(i);
        }
        test_methods(d1, d2);
    }
}

void test_default_int() {
    Deque<int> d1;
    std::deque<int> s_d1;
    test_methods(d1, s_d1);

    random_push_int(d1, s_d1);


    bool step = false;
    while(!d1.empty()) {
        if(step) {
            auto x = *d1.begin();
            auto y = *s_d1.begin();
            compare(x, y);
            d1.pop_front();
            s_d1.pop_front();
        } else{
            auto x = d1.back();
            auto y = s_d1.back();
            compare(x, y);
            d1.pop_back();
            s_d1.pop_back();
        }
        step = !step;
    }
    test_methods(d1,s_d1);
}

int main() {
    test_default_int();

    std::cout << "Finished";
}