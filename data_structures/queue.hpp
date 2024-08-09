#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>
#include "linked_list.hpp"

template <typename T>
class Queue
{
public:
    Queue();

    size_t size() const { return data.size(); }
    bool is_empty() const { return data.is_empty(); }
    bool contains(const T& value) { return data.contains(value); }

    T* to_array() const { return data.to_array(); }

private:
    LinkedList<T> data;
};

// ----------

#endif // QUEUE_H
