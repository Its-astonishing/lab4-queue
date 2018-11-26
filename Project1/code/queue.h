#pragma once

const int MAX_SIZE = 100000;
template <class T>
class queue
{
    int size = -1;
    int begin=0;
    int end= 0;
    int counter = 0;
    T* mem;
public:
    queue(int size)
    {
        if (size< 0 || size > MAX_SIZE)
            throw("error");
        this->size = size;
        mem = new T[size];
    }
    bool isFull()
    {
        return counter == size;
    }
    bool isEmpty()
    {
        return counter == 0;
    }
    void push_back(T elem)
    {
        if (isFull())
            throw("error");
        mem[end] = elem;
        counter++;
        end++;
        end %= size;
    }
    T pop()
    {
        if (isEmpty())
            throw("error");
        T tmp = mem[begin];
        counter--;
        begin++;
        begin %= size;
        return tmp;
    }
    int getSize()
    {
        return size;
    }
    ~queue()
    {
        delete[] mem;
    }
};