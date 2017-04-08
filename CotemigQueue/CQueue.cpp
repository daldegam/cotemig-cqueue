#include <stdio.h>
#include <memory.h>
#include <iostream>
using namespace std;

#include "CQueue.hpp"
using namespace Cotemig::Queue;

CQueue::CQueue(int size)
{
    p_fItems = new float[size];
    memset(p_fItems, 0, size);
    m_iMaxSize = size;
    m_iBegin = 0;
    m_iEnd = 0;

    m_bDebug = true;
}

CQueue::CQueue(const CQueue &queue)
{
	p_fItems = new float[queue.m_iMaxSize];
	memcpy(p_fItems, queue.p_fItems, sizeof(float) * queue.m_iMaxSize);

	m_iMaxSize = queue.m_iMaxSize;
	m_iBegin = queue.m_iBegin;
	m_iEnd = queue.m_iEnd;

	m_bDebug = queue.m_bDebug;
}

CQueue& CQueue::operator=(const CQueue& queue)
{
	// Same code of copy constructor
	p_fItems = new float[queue.m_iMaxSize];
	memcpy(p_fItems, queue.p_fItems, sizeof(float) * queue.m_iMaxSize);

	m_iMaxSize = queue.m_iMaxSize;
	m_iBegin = queue.m_iBegin;
	m_iEnd = queue.m_iEnd;

	m_bDebug = queue.m_bDebug;
	return *this;
}

CQueue::~CQueue()
{
	delete[] p_fItems;
}

int CQueue::GetBeginPosition()
{
    return m_iBegin;
}

void CQueue::Insert(float item)
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

float CQueue::Remove()
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

bool CQueue::IsEmpty()
{
    return Size() == 0;
}

bool CQueue::IsFull()
{
    return Size() == m_iMaxSize;
}

int CQueue::Size()
{
    return m_iEnd - m_iBegin;
}

int CQueue::MaxSize()
{
    return m_iMaxSize;
}

CQueue CQueue::operator+(CQueue queue)
{
    CQueue newQueue(this->MaxSize());

	int indexBeginCurrentQueue = this->GetBeginPosition();
	int indexBeginReceivedQueue = queue.GetBeginPosition();
    for(int i = 0, s = this->Size(); i < s; i++)
    {
		newQueue.Insert(p_fItems[(indexBeginCurrentQueue++) % m_iMaxSize] + queue[(indexBeginReceivedQueue++) % m_iMaxSize]);
    }

    return newQueue;
}

CQueue CQueue::operator+(float item)
{
    CQueue newQueue(this->MaxSize());

	int indexBeginCurrentQueue = this->GetBeginPosition();
    for(int i = 0, s = this->Size(); i < s; i++)
    {
		newQueue.Insert(p_fItems[(indexBeginCurrentQueue++) % m_iMaxSize] + item);
    }

    return newQueue;
}

CQueue& CQueue::operator+=(CQueue queue)
{
	int indexBeginCurrentQueue = this->GetBeginPosition();
	int indexBeginReceivedQueue = queue.GetBeginPosition();
    for(int i = 0, s = this->Size(); i < s; i++)
    {
		p_fItems[(indexBeginCurrentQueue++) % m_iMaxSize] += queue[(indexBeginReceivedQueue++) % m_iMaxSize];
    }

    return *this;
}

CQueue& CQueue::operator+=(float item)
{
	int indexBeginCurrentQueue = this->GetBeginPosition();
    for(int i = 0, s = this->Size(); i < s; i++)
    {
		p_fItems[(indexBeginCurrentQueue++) % m_iMaxSize] += item;
    }

    return *this;
}


float CQueue::operator[](int index) 
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

bool CQueue::operator==(CQueue queue)
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

bool CQueue::operator!=(CQueue queue)
{
    return !(*this == queue);
}

void CQueue::operator<<(float item)
{
    this->Insert(item);
}

void CQueue::operator>>(float& item)
{
    item = this->Remove();
}
