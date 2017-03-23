#include <stdio.h>
#include <iostream>
using namespace std;

#include "CQueue.hpp"
using namespace Cotemig::Queue;

/**
 * g++ CQueue.cpp queue-test.cpp && ./a.out
 */

void common_tests()
{
    CQueue myQueue(5);

    cout << "Queue IsEmpty: " << myQueue.IsEmpty() << endl;

    myQueue.Insert(1.0f);
    myQueue.Insert(2.0f);
    cout << "Current Queue Size: " << myQueue.Size() << endl;

    myQueue.Insert(3.0f);
    myQueue.Insert(4.0f);
    cout << "Current Queue Size: " << myQueue.Size() << endl;

    myQueue.Remove();

    cout << "Current Queue Size: " << myQueue.Size() << endl;

    myQueue.Insert(5.0f);
    myQueue.Insert(6.0f);

    cout << "Current Queue Size: " << myQueue.Size() << endl;
    cout << "Queue IsFull: " << myQueue.IsFull() << endl;

    myQueue.Remove();
    myQueue.Insert(7.0f);
    
    myQueue.Remove();
    myQueue.Insert(8.0f);
}

ostream& operator<<(ostream& stream, Cotemig::Queue::CQueue list)
{
    stream << "[";
    for(int i = 0; i < list.Size(); i++)
    {
        stream << list[i];
        
        if(i < list.Size() - 1)
        {
            stream << ",";
        }
    }
    stream << "]" << endl;
    return stream;
}


void operator_plus_tests() 
{
    CQueue q1(5);
    CQueue q2(5);

    q1.Insert(1.0f);
    q2.Insert(1.0f);

    q1.Insert(2.0f);
    q2.Insert(2.0f);

    q1.Insert(3.0f);
    q2.Insert(3.0f);

    CQueue qSum(5);

    qSum = q1 + q2;

    cout << q1;
    cout << q2;
    cout << qSum;

}

int main()
{
    //common_tests();   

    operator_plus_tests();

    return 0;
}