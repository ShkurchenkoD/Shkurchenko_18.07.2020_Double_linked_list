#pragma once

#include "Node.h"

template<class T>
class List
{
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int size = 0;
public:
    List();

    List(const List<T>& obj);
    List(List<T>&& obj)noexcept;
    List<T>& operator=(const List<T>& obj);
    List<T>& operator=(List<T>&& obj)noexcept;
    ~List();

    void push_back(T val);

    void push_front(T val);

    void insert(T val, int pos);

    void print_forward() const;

    void print_backward() const;

    void pop_front();
    void pop_back();
    void del(int pos);
    void sort_min_to_max();
    void sort_max_to_min();
};

template<class T>
void List<T>::insert(T val, int pos)
{
    if (pos < 0 || pos > size)
        return;
    if (pos == 0)
    {
        push_front(val);
        return;
    }
    if (pos == size)
    {
        push_back(val);
        return;
    }
    auto cur = head;
    for (int i = 0; i < pos - 1; ++i)
    {
        cur = cur->getNext();
    }
    auto tmp = new Node<T>(val);

    tmp->setPrev(cur);
    tmp->setNext(cur->getNext());
    cur->setNext(tmp);
    tmp->getNext()->setPrev(tmp);
    size++;
}

template<class T>
void List<T>::push_front(T val)
{
    auto tmp = new Node<T>(val);
    if (size == 0)
        head = tail = tmp;
    else
    {
        tmp->setNext(head);
        head->setPrev(tmp);
        head = tmp;
    }
    size++;
}

template<class T>
List<T>::List(const List<T>& obj)
{
    Node<T>* cur = obj.head;
    while (cur != nullptr)
    {
        push_back(cur->getData());
        cur = cur->getNext();
    }
}

template<class T>
inline List<T>::List(List<T>&& obj)noexcept
{
    head = obj.head;
    tail = obj.tail;
    size = obj.size;
    obj.head = nullptr;
    obj.tail = nullptr;
    obj.size = 0;
}

template<class T>
inline List<T>& List<T>::operator=(const List<T>& obj)
{
    if (this == &obj)
        return *this;
    while (size != 0)
        pop_front();
    Node<T>* tmp = obj.head;
    while (tmp)
    {
        push_back(tmp->getData());
        tmp = tmp->getNext();
    }
    return *this;
}

template<class T>
inline List<T>& List<T>::operator=(List<T>&& obj) noexcept
{
    if (this == &obj)
        return *this;
    while (size != 0)
        pop_front();
    head = obj.head;
    tail = obj.tail;
    size = obj.size;
    obj.head = nullptr;
    obj.tail = nullptr;
    obj.size = 0;
    return *this;
}

template<class T>
List<T>::~List()
{
    while (size != 0)
        pop_front();
}

template<class T>
void List<T>::pop_front()
{
    if (size == 0)
        return;
    if (size == 1)
    {
        delete head;
        head = tail = nullptr;
        size = 0;
        return;
    }
    head = head->getNext();
    delete head->getPrev();
    head->setPrev(nullptr);
    size--;
}

template<class T>
inline void List<T>::pop_back()
{
    if (size == 0)
        return;
    if (size == 1)
    {
        delete head;
        head = tail = nullptr;
        size = 0;
        return;
    }
    tail = tail->getPrev();
    delete tail->getNext();
    tail->setNext(nullptr);
    size--;
}

template<class T>
inline void List<T>::del(int pos)
{
    if(pos == 1)
    {
        pop_front(); 
        return;
    }
    if (pos == size)
    {
        pop_back();
        return;
    }
    if (size == 1)
    {
        delete head;
        head = tail = nullptr;
        size = 0;
        return;
    }
    if (pos == 0)
        return;
    Node<T>* tmp = head;
    for (int i = 1; i < pos; i++)
    {
        tmp = tmp->getNext();
    }
    Node<T>* tmp2 = tmp->getNext();
    tmp2->setPrev(tmp->getPrev());
    tmp->getPrev()->setNext(tmp2);
    delete tmp;
    size--;
}

template<class T>
inline void List<T>::sort_min_to_max()
{
    int count = size;
    while (count)
    {
        Node<T>* tmp = head;
        Node<T>* tmp2 = head->getNext();
        if (tmp->getPrev() == nullptr && tmp2->getNext() == nullptr && tmp->getData() > tmp2->getData())
        {
            tmp->setPrev(tmp2);
            tmp2->setNext(tmp);
            tmp->setNext(nullptr);
            tmp2->setPrev(nullptr);
            head = tmp2;
            tail = tmp;
            break;
        }
        if (tmp->getPrev() == nullptr && tmp->getData() > tmp2->getData())
        {
            tmp->setNext(tmp->getNext()->getNext());
            tmp->getNext()->setPrev(tmp);
            tmp2->setPrev(nullptr);
            tmp2->setNext(tmp);
            tmp->setPrev(tmp2);
            head = tmp2;
            tmp = tmp->getNext();
            tmp2 = tmp->getNext();
        }
        else
        {
            tmp = tmp->getNext();
            tmp2 = tmp->getNext();
        }

        while (tmp != tail && tmp2 != tail)
        {
            if (tmp->getData() > tmp2->getData())
            {
                tmp->setNext(tmp->getNext()->getNext());
                tmp->getNext()->setPrev(tmp);
                tmp->getPrev()->setNext(tmp2);
                tmp2->setPrev(tmp->getPrev());
                tmp2->setNext(tmp);
                tmp->setPrev(tmp2);
                tmp = tmp->getNext();
                tmp2 = tmp->getNext();
            }
            else
            {
                tmp = tmp->getNext();
                tmp2 = tmp->getNext();
            }
        }

        if (tmp2 == tail && tmp->getData() > tmp2->getData())
        {
            tmp->getPrev()->setNext(tmp2);
            tmp2->setPrev(tmp->getPrev());
            tmp2->setNext(tmp);
            tmp->setNext(nullptr);
            tmp->setPrev(tmp2);
            tail = tmp;
        }
        tmp = tmp2 = nullptr;
        count--;
    }
}


template<class T>
inline void List<T>::sort_max_to_min() 
{
    int count = size;
    while (count)
    {
        Node<T>* tmp = head;
        Node<T>* tmp2 = head->getNext();
        if (tmp->getPrev() == nullptr && tmp2->getNext() == nullptr && tmp->getData() < tmp2->getData())
        {
            tmp->setPrev(tmp2);
            tmp2->setNext(tmp);
            tmp->setNext(nullptr);
            tmp2->setPrev(nullptr);
            head = tmp2;
            tail = tmp;
            break;
        }
        if (tmp->getPrev() == nullptr && tmp->getData() < tmp2->getData())
        {
            tmp->setNext(tmp->getNext()->getNext());
            tmp->getNext()->setPrev(tmp);
            tmp2->setPrev(nullptr);
            tmp2->setNext(tmp);
            tmp->setPrev(tmp2);
            head = tmp2;
            tmp = tmp->getNext();
            tmp2 = tmp->getNext();
        }
        else
        {
            tmp = tmp->getNext();
            tmp2 = tmp->getNext();
        }

        while (tmp != tail&& tmp2 != tail)
        {
            if (tmp->getData() < tmp2->getData())
            {
                tmp->setNext(tmp->getNext()->getNext());
                tmp->getNext()->setPrev(tmp);
                tmp->getPrev()->setNext(tmp2);
                tmp2->setPrev(tmp->getPrev());
                tmp2->setNext(tmp);
                tmp->setPrev(tmp2);
                tmp = tmp->getNext();
                tmp2 = tmp->getNext();
            }
            else
            {
                tmp = tmp->getNext();
                tmp2 = tmp->getNext();
            }
        }

        if (tmp2 == tail && tmp->getData() < tmp2->getData())
        {
            tmp->getPrev()->setNext(tmp2);
            tmp2->setPrev(tmp->getPrev());
            tmp2->setNext(tmp);
            tmp->setNext(nullptr);
            tmp->setPrev(tmp2);
            tail = tmp;
        }
        tmp = tmp2 = nullptr;
        count--;
    }
}

template<class T>
void List<T>::print_forward() const
{
    auto cur = head;
    while (cur != nullptr)
    {
        cout << cur->getData() << " ";
        cur = cur->getNext();
    }
    cout << endl;
}

template<class T>
void List<T>::print_backward() const
{
    auto cur = tail;
    while (cur != nullptr)
    {
        cout << cur->getData() << " ";
        cur = cur->getPrev();
    }
    cout << endl;
}

template<class T>
void List<T>::push_back(T val)
{
    auto tmp = new Node<T>(val);
    if (size == 0)
        head = tail = tmp;
    else
    {
        tmp->setPrev(tail);
        tail->setNext(tmp);
        tail = tmp;
    }
    size++;
}


template<class T>
List<T>::List() = default;


