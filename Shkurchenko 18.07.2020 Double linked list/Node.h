#pragma once

#include <iostream>
using namespace std;
template <class T>
class Node
{
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
public:
    Node(T val);
    Node<T>* getNext()const;
    Node<T>* getPrev()const;
    T getData()const;
    void setNext(Node<T>* val);
    void setPrev(Node<T>* val);
    void setData(T val);
};

template<class T>
Node<T>::Node(T val)
{
    data = val;
}

template<class T>
Node<T>* Node<T>::getNext() const
{
    return next;
}

template<class T>
Node<T>* Node<T>::getPrev() const
{
    return prev;
}

template<class T>
T Node<T>::getData() const
{
    return data;
}

template<class T>
void Node<T>::setNext(Node<T>* val)
{
    next = val;
}

template<class T>
void Node<T>::setPrev(Node<T>* val)
{
    prev = val;
}

template<class T>
void Node<T>::setData(T val)
{
    data = val;
}
