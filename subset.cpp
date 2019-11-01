//
// Created by tima on 31.05.2019.
//

#include <iostream>
#include "Deque.hpp"
#include "Deque.cpp"
#include "randomized_queue.hpp"
#include "randomized_queue.cpp"

using std::cout;
using std::cin;
int main() {
    int k;
    cout << "Number of items: ";
    cin >> k;
    Deque<std::string> deque;
    randomized_queue<std::string> queue;
    std::string item;
    for (int i = 0; i < k; ++i) {
        cin >> item;
        deque.push_back(item);
        queue.enqueue(item);
    }
    cout << "Number of elements that you want: ";
    int l;
    cin >> l;
    if (l > k) {
        cout << "It more than you cin\n";
        return 0;
    }
    cout << "Randomized queue: \n";
    for (int i = 0; i < l; ++i) {
        cout << queue.dequeue() << ' ';
    }
    cout << "\n Deque: \n";
    for (int i = 0; i < l; ++i) {
        cout << deque.back() << ' ';
        deque.pop_back();
    }
}