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
    delete [] p_fItems;
}

void Cotemig::Queue::CQueue::Insert(float item)
{
    if(IsFull())
    {
        cout << "Erro, this queue is full" << endl;
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

Cotemig::Queue::CQueue Cotemig::Queue::CQueue::operator+(Cotemig::Queue::CQueue list)
{
    Cotemig::Queue::CQueue newList(this->MaxSize());

    for(int i = 0, s = this->Size(); i < s; i++)
    {
        newList.Insert(this->Remove() + list.Remove());
    }

    return newList;
}