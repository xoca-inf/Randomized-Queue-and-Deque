//
// Created by tima on 31.05.2019.
//

#include <iostream>
#include <assert.h>
#include "randomized_queue.hpp"
#include "randomized_queue.cpp"


using std::cout;
using std::cin;
using std::endl;
void testMethods() {
    cout << "==========================================\n";
    cout << "\tTESTING METHODS\n";
    randomized_queue<std::string> queue;
    cout << "Testing empty(): " << (queue.empty() ? "empty\n" : "not empty\n");
    cout << "Testing size(): " << queue.size() << endl;
    queue.enqueue("test");
    cout << "Testing enqueue(): " << queue.dequeue() << '\n';
    queue.enqueue("random 1");
    queue.enqueue("random 2");
    cout << "Testing sample(): " << queue.sample() << '\n';
    cout << "Testing enqueue() was when testing last tests\n\n";
}

void testingIterator() {
    cout << "=============================================\n";
    cout << "\tTESTING ITERATOR & QUEUE WITH STRUCT\n";
    struct kek {
        int a, b, c;
        kek *lol, *omegalul;
        kek(int _a, int _b, int _c) : a(_a), b(_b), c(_c){
            lol = nullptr;
            omegalul = nullptr;
        }
        std::string tostring() {
            std::string temp;
            temp += a;
            temp += "toStr";
        }
        ~kek() {
            delete lol;
            delete omegalul;
        }
    };
    randomized_queue<kek*> queue;
    for (int i = 0; i < 5; ++i) {
        queue.enqueue(new kek(i, i-1, i+1));
    }
    randomized_queue<kek*>::iterator iterator = queue.begin();
    randomized_queue<kek*>::iterator it(iterator);
    for (;iterator != queue.end(); ++iterator) {
        cout << (*iterator)->a << ' ' << (*iterator)->b << ' ' << (*iterator)->c << '\n';
    }
    cout << "copying iterator\n";
    for (;it != queue.end(); ++it) {
        cout << (*it)->a << ' ' << (*it)->b << ' ' << (*it)->c << '\n';
    }
    if (it == iterator) {
        cout << "iterator's are equal\n";
    }
    cout << "what we expect with foreach\n";
    for (kek*& indx : queue) {
        cout << indx->a << ' ' << indx->b << ' ' << indx->c << '\n';
    }
}

int main() {
    testMethods();
    testingIterator();
}