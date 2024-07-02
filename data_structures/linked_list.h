#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>
#include <initializer_list>

template <typename T>
class LinkedListNode
{
public:
    LinkedListNode();
    LinkedListNode(const T& value);
    LinkedListNode(const T& value, LinkedListNode* next);

    T value;
    LinkedListNode*  next;
};

template <typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const std::initializer_list<T>& values);

    void append_back(const T& value);
    void append_front(const T& value);
    void append_after(LinkedListNode<T>* prev, const T& value);
    void append_before(LinkedListNode<T>* next, const T& value);
    void append_by_index(size_t index, const T& value);

    T* to_array();

    size_t size() { return sz; }
    LinkedListNode<T>* head() { return _head; }

private:
    LinkedListNode<T>* _head;
    size_t sz;
};

#endif // LINKEDLIST_H
