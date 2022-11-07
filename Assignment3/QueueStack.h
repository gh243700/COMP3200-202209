#pragma once
#include "SmartStack.h"
#include "Capture.h"
#include <queue>
#include <stack>
#include <cassert>
namespace assignment3
{
	template <typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);
		QueueStack(const QueueStack& rhs) = default;
		QueueStack operator=(const QueueStack& other);
		bool operator==(const QueueStack& other);
		~QueueStack() = default;

		void Enqueue(const T& number);
		T Peek() const;
		T Dequeue();
		T GetMax() const;
		T GetMin() const;
		double GetAverage() const;
		T GetSum() const;
		unsigned int GetCount() const;
		unsigned int GetStackCount() const;

	private:
		unsigned int mMaxStackSize;
		T mSum;
		std::queue<SmartStack<T> > mSmartStacks;
	};

	template <typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
		, mSum(static_cast<T>(0))
	{

	}

	template <typename T>
	QueueStack<T> QueueStack<T>::operator=(const QueueStack& other)
	{
		if (this == &other)
		{
			return *this;
		}

		mSmartStacks = other.mSmartStacks;
		mMaxStackSize = other.mMaxStackSize;
		mSum = other.mSum;
	}

	template <typename T>
	bool QueueStack<T>::operator==(const QueueStack<T>& other)
	{
		if (this == &other)
		{
			return true;
		}

		return mSmartStacks == other.mSmartStacks && mMaxStackSize == other.mMaxStackSize && mSum == other.mSum;
	}


	template <typename T>
	void QueueStack<T>::Enqueue(const T& number)
	{
		mSum += number;
		if (mSmartStacks.size() == 0 || mSmartStacks.back().GetCount() >= mMaxStackSize)
		{
			SmartStack<T> smartStack;
			smartStack.Push(number);
			mSmartStacks.push(smartStack);
			return;
		}

		mSmartStacks.back().Push(number);

	}

	template <typename T>
	T QueueStack<T>::Peek() const
	{
		assert(mSmartStacks.size() > 0 && mSmartStacks.front().GetCount() > 0);
		return mSmartStacks.front().Peek();
	}

	template <typename T>
	T QueueStack<T>::Dequeue()
	{
		assert(mSmartStacks.size() > 0 && mSmartStacks.front().GetCount() > 0);

		T value = mSmartStacks.front().Pop();
		mSum -= value;

		if (mSmartStacks.front().GetCount() == 0)
		{
			mSmartStacks.pop();
		}

		return value;
	}

	template <typename T>
	T QueueStack<T>::GetMax() const
	{
		if (mSmartStacks.size() == 0 || mSmartStacks.back().GetCount() == 0)
		{
			return std::numeric_limits<T>::min();
		}

		std::queue<SmartStack<T> > copy = mSmartStacks;
		T max = copy.front().GetMax();
		copy.pop();

		T value;

		while (copy.size() != 0)
		{
			value = copy.front().GetMax();
			if (max < value)
			{
				max = value;
			}
			copy.pop();
		}

		return max;
	}

	template <typename T>
	T QueueStack<T>::GetMin() const
	{

		if (mSmartStacks.size() == 0 || mSmartStacks.back().GetCount() == 0)
		{
			return std::numeric_limits<T>::max();
		}
		std::queue<SmartStack<T> > copy = mSmartStacks;
		T min = copy.front().GetMin();
		copy.pop();

		T value;
		while (copy.size() != 0)
		{
			value = copy.front().GetMin();
			if (min > value)
			{
				min = value;
			}
			copy.pop();
		}

		return min;
	}

	template <typename T>
	double QueueStack<T>::GetAverage() const
	{
		assert(mSmartStacks.size() > 0 && mSmartStacks.front().GetCount() > 0);
		return GetSum() / GetCount();
	}

	template <typename T>
	T QueueStack<T>::GetSum() const
	{
		return mSum;
	}

	template <typename T>
	unsigned int QueueStack<T>::GetCount() const
	{
		if (mSmartStacks.size() == 0)
		{
			return 0;
		}

		int count;
		const size_t size = mSmartStacks.size();
		switch (size)
		{
		case 1:
			count = mSmartStacks.front().GetCount();
			break;
		case 2:
			count = mSmartStacks.front().GetCount() + mSmartStacks.back().GetCount();
			break;
		default:
			count = mMaxStackSize * (size - 2) + mSmartStacks.front().GetCount() + mSmartStacks.back().GetCount();
			break;
		}

		return count;
	}

	template <typename T>
	unsigned int QueueStack<T>::GetStackCount() const
	{
		return mSmartStacks.size();
	}
}