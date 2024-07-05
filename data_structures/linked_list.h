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

    void remove_back();
    void remove_front();

    void clear();

    size_t size() const { return sz; }
    bool is_empty() const { return sz > 0 ? false : true; };
    bool contains(const T& value) const;
    LinkedListNode<T>* head() const { return _head; }

    T* to_array() const;

private:
    LinkedListNode<T>* _head;
    size_t sz;
};

#endif // LINKEDLIST_H
