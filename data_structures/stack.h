#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include "linked_list.h"

template <typename T>
class Stack
{
public:
    Stack();

    void push(const T& value);
    void pop();

    T peek() const;

    size_t size() const { return data.size(); }
    bool is_empty() const { return data.is_empty(); }
    bool contains(const T& value) const { return data.contains(value); }

    T* to_array() const { return data.to_array(); }

private:
    LinkedList<T> data;
};

#endif // STACK_H
