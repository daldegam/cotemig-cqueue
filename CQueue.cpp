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

    if(m_bDebug)
    {
        cout << "Insert item (" << item << ") into Queue" << endl;
    }

    p_fItems[m_iEnd++] = item;
}

float Cotemig::Queue::CQueue::Remove()
{
    if(IsEmpty())
    {
        cout << "Erro, this queue is empty" << endl;
        return 0;
    }

    float value = p_fItems[m_iBegin++];
    if(m_bDebug)
    {
        cout << "Remove item (" << value << ") from Queue" << endl;
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

int main()
{
    CQueue myQueue(10);

    cout << "Queue IsEmpty: " << myQueue.IsEmpty() << endl;

    for (int a = 0; a < 10; a++)
    {
        myQueue.Insert(a);
    }

    cout << "Queue IsFull: " << myQueue.IsFull() << endl;

    cout << "Current Queue Size: " << myQueue.Size() << endl;

    for (int a = 0; a < 3; a++)
    {
        cout << "\tReturned value: " << myQueue.Remove() << endl;
    }

    cout << "Current Queue Size: " << myQueue.Size() << endl;

    for (int a = 0; a < 2; a++)
    {
        cout << "\tReturned value: " << myQueue.Remove() << endl;
    }

    cout << "Current Queue Size: " << myQueue.Size() << endl;


    cout << "Queue IsEmpty: " << myQueue.IsEmpty() << endl;

    return 0;
}
