#include <vector>
#include <queue>
#include <iostream>
#include "SmartStack.h"
#include "QueueStack.h"
#include "SmartQueue.h"

int main()
{
	const double EPSILON = 0.0009765625;
	{
		SmartStack<int> ss1;
		ss1.Push(1);
		assert(ss1.Peek() == 1);
		assert(ss1.GetMax() == 1);
		assert(ss1.GetMin() == 1);


		ss1.Push(2);
		assert(ss1.Peek() == 2);
		ss1.Push(3);
		assert(ss1.Peek() == 3);
		ss1.Push(4);
		assert(ss1.Peek() == 4);
		ss1.Push(5);
		assert(ss1.Peek() == 5);
		assert(ss1.GetMax() == 5);
		assert(ss1.GetMin() == 1);


		assert(ss1.Pop() == 5);
		assert(ss1.Peek() == 4);
		assert(ss1.GetMax() == 4);
		assert(ss1.GetMin() == 1);
	}
	{
		SmartStack<float> ss;

		ss.Push(3.4999f);
		ss.Push(1.2f);
		ss.Push(4.6555f);
		ss.Push(3.3299f);
		ss.Push(10.2f);
		ss.Push(1.1f);
		ss.Push(-5.9f);
		ss.Push(1.1f);
		ss.Push(-12.4f);
		ss.Push(9.2f);

		assert(ss.GetCount() == 10U);
		assert(ss.Peek() == 9.2f);
		assert(ss.GetMax() == 10.2f);
		assert(ss.GetMin() == -12.4f);
		assert(std::abs(ss.GetSum() - 15.985301f) <= EPSILON);
		assert(std::abs(ss.GetAverage() - 1.599) <= EPSILON);
		assert(std::abs(ss.GetVariance() - 40.057) <= EPSILON);
		assert(std::abs(ss.GetStandardDeviation() - 6.329) <= EPSILON);
		assert(ss.Peek() == 9.2f);
	}

	{
		SmartStack<int> s;
		s.Push(6);
		s.Push(5);
		s.Push(-2); // [ 6, 5, -2 ]

		int sum = s.GetSum();
		assert(sum == 9);
		double average = s.GetAverage(); // 3.000
		assert(std::abs(average - 3.000) <= EPSILON);
	
		double variance = s.GetVariance(); // 12.667
		assert(std::abs(variance - 12.667) <= EPSILON);
		double standardDeviation = s.GetStandardDeviation(); // 3.559
		assert(std::abs(standardDeviation - 3.559) <= EPSILON);
		unsigned int count = s.GetCount(); // 3
		assert(count == 3);
	}

	{
		SmartQueue<int> q;

		q.Enqueue(6); // [ 6 ]
		assert(q.GetMax() == 6);
		assert(q.GetMin() == 6);
		assert(q.GetSum() == 6);
		assert(q.Peek() == 6);
		q.Enqueue(5); // [ 6, 5 ]
		assert(q.GetMax() == 6);
		assert(q.GetMin() == 5);
		assert(q.GetSum() == 11);
		assert(q.Peek() == 6);

		q.Enqueue(-2); // [ 6, 5, -2 
		assert(q.GetMax() == 6);
		assert(q.GetMin() == -2);
		assert(q.GetSum() == 9);
		assert(q.Peek() == 6);


		double average = q.GetAverage(); // 3.000
		assert(std::abs(average - 3.000) <= EPSILON);
		double variance = q.GetVariance(); // 12.667
		assert(std::abs(variance - 12.667) <= EPSILON);
		double standardDeviation = q.GetStandardDeviation(); // 3.559
		assert(std::abs(standardDeviation - 3.559) <= EPSILON);
		unsigned int count = q.GetCount(); // 3
		assert(count == 3);
		
		assert(q.Dequeue() == 6);
		assert(q.Peek() == 5);
		assert(q.GetMax() == 5);
		assert(q.GetMin() == -2);
		assert(q.GetSum() == 3);
	}


	{
		QueueStack<int> qs(3);
		qs.Enqueue(1); // [ [ 1 ] ]
		assert(qs.GetCount() == 1);
		assert(qs.GetStackCount() == 1);
		assert(qs.GetMax() == 1);
		assert(qs.GetMin() == 1);
		assert(qs.GetSum() == 1);
		assert(qs.Peek() == 1);
		qs.Enqueue(2); // [ [ 1, 2 ] ]
		assert(qs.GetCount() == 2);
		assert(qs.GetStackCount() == 1);
		assert(qs.GetMax() == 2);
		assert(qs.GetMin() == 1);
		assert(qs.GetSum() == 3);
		assert(qs.Peek() == 2);
		qs.Enqueue(3); // [ [ 1, 2, 3 ] ]
		assert(qs.GetCount() == 3);
		assert(qs.GetStackCount() == 1);
		assert(qs.GetMax() == 3);
		assert(qs.GetMin() == 1);
		assert(qs.GetSum() == 6);
		assert(qs.Peek() == 3);
		qs.Enqueue(4); // [ [ 1, 2, 3 ], [ 4 ] ]
		assert(qs.GetCount() == 4);
		assert(qs.GetStackCount() == 2);
		assert(qs.GetMax() == 4);
		assert(qs.GetMin() == 1);
		assert(qs.GetSum() == 10);
		assert(qs.Peek() == 3);
		qs.Enqueue(5); // [ [ 1, 2, 3 ], [ 4, 5 ] ]
		assert(qs.GetCount() == 5);
		assert(qs.GetStackCount() == 2);
		assert(qs.GetMax() == 5);
		assert(qs.GetMin() == 1);
		assert(qs.GetSum() == 15);
		assert(qs.Peek() == 3);
		double average = qs.GetAverage(); // 3.000
		assert(std::abs(average - 3.000) <= EPSILON);
		
		assert(qs.Dequeue() == 3);  // [ [ 1, 2 ], [ 4, 5 ] ]
		assert(qs.GetCount() == 4);
		assert(qs.GetStackCount() == 2);
		assert(qs.GetMax() == 5);
		assert(qs.GetMin() == 1);
		assert(qs.GetSum() == 12);
		assert(qs.Peek() == 2);

		assert(qs.Dequeue() == 2);  // [ [ 1 ], [ 4, 5 ] ]
		assert(qs.GetCount() == 3);
		assert(qs.GetStackCount() == 2);
		assert(qs.GetMax() == 5);
		assert(qs.GetMin() == 1);
		assert(qs.GetSum() == 10);
		assert(qs.Peek() == 1);

		assert(qs.Dequeue() == 1);  // [ [ 1 ], [ 4, 5 ] ]
		assert(qs.GetCount() == 2);
		assert(qs.GetStackCount() == 1);
		assert(qs.GetMax() == 5);
		assert(qs.GetMin() == 4);
		assert(qs.GetSum() == 9);
		assert(qs.Peek() == 5);
	}
	{
		const double EPSILON = 0.0009765625;

		SmartStack<float> ss;

		ss.Push(3.4999f);
		ss.Push(1.2f);
		ss.Push(4.6555f);
		ss.Push(3.3299f);
		ss.Push(10.2f);
		ss.Push(1.1f);
		ss.Push(-5.9f);
		ss.Push(1.1f);
		ss.Push(-12.4f);
		ss.Push(9.2f);

		assert(ss.GetCount() == 10U);
		assert(ss.Peek() == 9.2f);
		assert(ss.GetMax() == 10.2f);
		assert(ss.GetMin() == -12.4f);
		assert(std::abs(ss.GetSum() - 15.985301f) <= EPSILON);
		assert(std::abs(ss.GetAverage() - 1.599) <= EPSILON);
		assert(std::abs(ss.GetVariance() - 40.057) <= EPSILON);
		assert(std::abs(ss.GetStandardDeviation() - 6.329) <= EPSILON);
		assert(ss.Peek() == 9.2f);

		float popped1 = ss.Pop();
		float popped2 = ss.Pop();

		assert(popped1 == 9.2f);
		assert(popped2 == -12.4f);
		assert(ss.GetCount() == 8U);
		assert(ss.Peek() == 1.1f);
		assert(ss.GetMax() == 10.2f);
		assert(ss.GetMin() == -5.9f);
		assert(std::abs(ss.GetSum() - 19.1853008f) <= EPSILON);
		assert(std::abs(ss.GetAverage() - 2.398) <= EPSILON);
		assert(std::abs(ss.GetVariance() - 17.714) <= EPSILON);
		assert(std::abs(ss.GetStandardDeviation() - 4.209) <= EPSILON);
	
	
	}
	

	system("pause");
}