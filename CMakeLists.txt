cmake_minimum_required(VERSION 3.14)
project(Queue_HW2)

set(CMAKE_CXX_STANDARD 17)

#add_executable(Queue_HW2 main.cpp Deque.h randomized_queue.h subset.h Deque.cpp)
add_executable(Queue_HW2 Deque.cpp Deque.hpp randomized_queue.hpp randomized_queue.cpp randomized_queue_test.cpp)