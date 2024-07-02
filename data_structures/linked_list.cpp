#include "linked_list.h"
#include <stdexcept>
#include <string>

template <typename T>
LinkedListNode<T>::LinkedListNode()
{
    value = T();
    next = nullptr;
}

template <typename T>
LinkedListNode<T>::LinkedListNode(const T& value)
{
    this->value = value;
    next = nullptr;
}

template <typename T>
LinkedListNode<T>::LinkedListNode(const T& value, LinkedListNode<T>* next)
{
    this->value = value;
    this->next = next;
}

template class LinkedListNode<int>;
template class LinkedListNode<float>;
template class LinkedListNode<double>;
template class LinkedListNode<std::string>;

template <typename T>
LinkedList<T>::LinkedList()
{
    _head = nullptr;
    sz = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const std::initializer_list<T>& values)
{
    _head = nullptr;
    sz = 0;
    for (const T& value : values)
    {
        append_back(value);
    }
}

template <typename T>
void LinkedList<T>::append_back(const T& value)
{
    LinkedListNode<T>* node = new LinkedListNode<T>(value);

    if (_head == nullptr)
    {
        _head = node;
    }
    else
    {
        LinkedListNode<T>* current = _head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = node;
    }

    sz += 1;
}

template <typename T>
void LinkedList<T>::append_front(const T& value)
{
    LinkedListNode<T>* node = new LinkedListNode<T>(value);

    if (_head != nullptr)
    {
        node->next = _head;
    }
    _head = node;

    sz += 1;
}

template <typename T>
void LinkedList<T>::append_after(LinkedListNode<T>* prev, const T& value)
{
    if (prev == nullptr)
    {
        throw std::invalid_argument("LinkedListNode pointer value is nullptr.");
    }

    LinkedListNode<T>* node = new LinkedListNode<T>(value);

    node->next = prev->next;
    prev->next = node;

    sz += 1;
}

template <typename T>
void LinkedList<T>::append_before(LinkedListNode<T>* next, const T& value)
{
    if (next == nullptr)
    {
        throw std::invalid_argument("LinkedListNode pointer value is nullptr.");
    }

    LinkedListNode<T>* node = new LinkedListNode<T>(value);

    LinkedListNode<T>* current = _head;
    while (current->next != next)
    {
        current = current->next;
    }

    current->next = node;
    node->next = next;

    sz += 1;
}

template <typename T>
void LinkedList<T>::append_by_index(size_t index, const T& value)
{
    if (index < 0 || index > sz)
    {
        throw std::out_of_range("LinkedList index out of range.");
    }

    LinkedListNode<T>* node = new LinkedListNode<T>(value);

    if (_head != nullptr)
    {
        size_t i = 0;
        LinkedListNode<T>* current = _head;
        while (i < index - 1)
        {
            current = current->next;
            i++;
        }

        node->next = current->next;
        current->next = node;
    }
    else
    {
        _head = node;
    }

    sz += 1;
}

template <typename T>
T* LinkedList<T>::to_array()
{
    T* arr = new T[sz];
    LinkedListNode<T>* current = _head;
    for (size_t i = 0; i < sz; ++i)
    {
        arr[i] = current->value;
        current = current->next;
    }
    return arr;
}

template class LinkedList<int>;
template class LinkedList<float>;
template class LinkedList<double>;
template class LinkedList<std::string>;
