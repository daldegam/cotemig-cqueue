#include <stdio.h>
#include <memory.h>
#include <iostream>
using namespace std;

#include "CQueue.hpp"
using namespace Cotemig::Queue;

Cotemig::Queue::CQueue::CQueue(int size)
{
    p_fItems = new float[size];
    memset(p_fItems, 0, size);
    m_iMaxSize = size;
    m_iBegin = 0;
    m_iEnd = 0;

    m_bDebug = true;
}

Cotemig::Queue::CQueue::~CQueue()
{
    // delete [] p_fItems;
}

int Cotemig::Queue::CQueue::GetBeginPosition()
{
    return m_iBegin;
}

void Cotemig::Queue::CQueue::Insert(float item)
{
    if(IsFull())
    {
        cout << "Error, this queue is full" << endl;
        return;
    }

    int index = ((m_iEnd++) % m_iMaxSize);

    if(m_bDebug)
    {
        cout << "Insert item[" << index << "](" << item << ") into Queue" << endl;
    }

    p_fItems[index] = item;
}

float Cotemig::Queue::CQueue::Remove()
{
    if(IsEmpty())
    {
        cout << "Erro, this queue is empty" << endl;
        return 0;
    }

    int index = ((m_iBegin++) % m_iMaxSize);

    float value = p_fItems[index];
    if(m_bDebug)
    {
        cout << "Remove item[" << index << "](" << value << ") from Queue" << endl;
    }
    
    return value;
}

bool Cotemig::Queue::CQueue::IsEmpty()
{
    return Size() == 0;
}

bool Cotemig::Queue::CQueue::IsFull()
{
    return Size() == m_iMaxSize;
}

int Cotemig::Queue::CQueue::Size()
{
    return m_iEnd - m_iBegin;
}

int Cotemig::Queue::CQueue::MaxSize()
{
    return m_iMaxSize;
}

Cotemig::Queue::CQueue Cotemig::Queue::CQueue::operator+(Cotemig::Queue::CQueue queue)
{
    CQueue newQueue(this->MaxSize());

    for(int i = 0, s = this->Size(); i < s; i++)
    {
        newQueue.Insert(p_fItems[i] + queue[i]);
    }

    return newQueue;
}

Cotemig::Queue::CQueue Cotemig::Queue::CQueue::operator+(float item)
{
    CQueue newQueue(this->MaxSize());

    for(int i = 0, s = this->Size(); i < s; i++)
    {
        newQueue.Insert(p_fItems[i] + item);
    }

    return newQueue;
}


Cotemig::Queue::CQueue& Cotemig::Queue::CQueue::operator+=(Cotemig::Queue::CQueue queue)
{
    for(int i = 0, s = this->Size(); i < s; i++)
    {
        p_fItems[i] += queue[i];
    }

    return *this;
}

Cotemig::Queue::CQueue& Cotemig::Queue::CQueue::operator+=(float item)
{
    for(int i = 0, s = this->Size(); i < s; i++)
    {
        p_fItems[i] += item;
    }

    return *this;
}


float Cotemig::Queue::CQueue::operator[](int index) 
{
    if(index < 0 || index > m_iMaxSize)
    {
        if(m_bDebug)
        {
            cout << "Error, index[" << index << "] mismatch" << endl;
        }
        return 0;
    }

    return p_fItems[index];
}

bool Cotemig::Queue::CQueue::operator==(Cotemig::Queue::CQueue queue)
{
    if (this->MaxSize() != queue.MaxSize())
    {
        return true;
    }

    for (int i = 0; i < this->MaxSize(); i++)
    {
        if (p_fItems[i] != queue[i])
        {
            return false;
        }
    }
    return true;
}

bool Cotemig::Queue::CQueue::operator!=(Cotemig::Queue::CQueue queue)
{
    return !(*this == queue);
}

void Cotemig::Queue::CQueue::operator<<(float item)
{
    this->Insert(item);
}

void Cotemig::Queue::CQueue::operator>>(float& item)
{
    item = this->Remove();
}
