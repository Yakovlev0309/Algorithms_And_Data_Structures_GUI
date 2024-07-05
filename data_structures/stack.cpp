#include "stack.h"
#include <string>

template <typename T>
Stack<T>::Stack() {}

template <typename T>
void Stack<T>::push(const T& value)
{
    // data.append_back(value);
    data.append_front(value);
}

template <typename T>
void Stack<T>::pop()
{
    // data.remove_back();
    data.remove_front();
}

template <typename T>
T Stack<T>::peek() const
{
    if (size() > 0)
    {
        return data.head()->value;
    }
    else
    {
        return NULL;
    }
}

template class Stack<int>;
template class Stack<float>;
template class Stack<double>;
template class Stack<std::string>;
