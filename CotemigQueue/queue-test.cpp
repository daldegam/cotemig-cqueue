#include <stdio.h>
#include <iostream>
using namespace std;

#include "CQueue.hpp"
using namespace Cotemig::Queue;

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

    cout << myQueue;
}

void operator_plus_queue_tests() 
{
    CQueue q1(5);
    CQueue q2(5);

	q1.Insert(1.0f);
	q1.Remove();  // Mudar a posição do valor de [0] para [1]

	q1.Insert(1.0f);
	q1.Remove();  // Mudar a posição do valor de [1] para [2]

	// Vamos inserir na posição [2] da queue para verificar se a soma está correta
	// No caso a soma deve ser iniciada de q1[2] + q2[0] e seguir normalmente
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

    cout << q1;
    cout << q2;
}

void operator_plus_float_tests() 
{
	CQueue q1(5);
	q1.Insert(1.0f);
	q1.Remove();
	
	q1.Insert(1.0f);
	q1.Remove();

	q1.Insert(1.0f);
    q1.Insert(2.0f);
    q1.Insert(3.0f);

    CQueue qSum(5);

    cout << q1;
    cout << qSum;

    qSum = q1 + 2.5f;

    cout << q1;
    cout << qSum;

    qSum = 1.5f + q1;

    cout << q1;
    cout << qSum;
}

void operator_plusequal_queue_tests() 
{
    CQueue q1(5);
    CQueue q2(5);

	q1.Insert(1.0f);
	q1.Remove();

	q1.Insert(1.0f);
	q1.Remove();

	q1.Insert(1.0f);
    q2.Insert(1.0f);

    q1.Insert(2.0f);
    q2.Insert(2.0f);

    q1.Insert(3.0f);
    q2.Insert(3.0f);

    cout << q1;
    cout << q2;

    q1 += q2;

    cout << q1;
    cout << q2;

    q1 += 10.f;

    cout << q1;
    cout << q2;
}

void operator_equals_and_notequals_queue_tests() 
{
    CQueue q1(5);
    CQueue q2(5);

    q1.Insert(1.0f);
    q2.Insert(1.0f);

    q1.Insert(2.0f);
    q2.Insert(2.0f);

    q1.Insert(3.0f);
    q2.Insert(3.0f);


    cout << "q1 == q2 result: " << (q1 == q2) << endl;

    cout << "q1 != q2 result: " << (q1 != q2) << endl;
}

void operator_doubleless_tests()
{
    CQueue q1(5);
    q1 << 1.0f;
    q1 << 2.0f;
    q1 << 3.0f;
       
    cout << q1;

    float t;

    q1 >> t;

    cout << "t = " << t << endl;

    cout << q1;
}

int main()
{
    common_tests();   

    operator_plus_queue_tests();
    
	operator_plus_float_tests();
    
	operator_plusequal_queue_tests();
    
	operator_equals_and_notequals_queue_tests();

    operator_doubleless_tests();
	
	getchar();

    return 0;
}