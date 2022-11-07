#pragma once
#include <stack>
#include "Capture.h"
#include <cassert>
#include <limits>
#include <cmath>
namespace assignment3
{
	template <typename T>
	class SmartStack
	{
	public:
		SmartStack() = default;
		SmartStack(const SmartStack& other) = default;
		SmartStack operator=(const SmartStack& other);
		bool operator==(const SmartStack& other);

		~SmartStack() = default;

		void Push(T value);
		T Pop();
		T Peek() const;
		T GetMax() const;
		T GetMin() const;
		double GetAverage() const;
		T GetSum() const;
		double GetVariance() const;
		double GetStandardDeviation() const;
		unsigned int GetCount() const;


	private:
		std::stack<Capture<T> > mCapture;
	};

	template <typename T>
	SmartStack<T> SmartStack<T>::operator=(const SmartStack<T>& other)
	{
		if (this == &other)
		{
			return *this;
		}

		mCapture = other.mCapture;
	}

	template <typename T>
	bool SmartStack<T>::operator==(const SmartStack<T>& other)
	{
		if (this == &other)
		{
			return true;
		}

		return mCapture == other.mCapture;
	}



	template <typename T>
	inline void SmartStack<T>::Push(T value)
	{
		Capture<T> capture;
		if (mCapture.size() == 0)
		{
			capture = Capture<T>();
		}
		else
		{
			capture = mCapture.top();
		}
		mCapture.push(Capture<T>(value, capture));
	}

	template<typename T>
	inline T SmartStack<T>::Pop()
	{
		assert(mCapture.size() != 0);

		T value = mCapture.top().GetValue();
		mCapture.pop();
		return value;
	}


	template <typename T>
	inline T SmartStack<T>::Peek() const
	{
		assert(mCapture.size() != 0);

		return mCapture.top().GetValue();
	}


	template <typename T>
	inline T SmartStack<T>::GetMax() const
	{
		if (mCapture.size() == 0)
		{
			return std::numeric_limits<T>::max();
		}

		return mCapture.top().GetMax();
	}

	template <typename T>
	inline T SmartStack<T>::GetMin() const
	{
		if (mCapture.size() == 0)
		{
			return std::numeric_limits<T>::min();
		}

		return mCapture.top().GetMin();
	}

	template <typename T>
	inline double SmartStack<T>::GetAverage() const
	{
		return mCapture.top().GetSum() / static_cast<double>(mCapture.size());
	}

	template <typename T>
	inline T SmartStack<T>::GetSum() const
	{
		return mCapture.top().GetSum();
	}

	template <typename T>
	inline double SmartStack<T>::GetVariance() const
	{
		Capture<T> capture = mCapture.top();
		T sum = capture.GetSum();
		double avg = sum / static_cast<double>(mCapture.size());
		return (capture.GetSumOfPow() - 2 * avg * sum + mCapture.size() * std::pow(avg, 2)) / static_cast<double>(mCapture.size());
	}

	template <typename T>
	inline double SmartStack<T>::GetStandardDeviation() const
	{
		return std::sqrt(SmartStack<T>::GetVariance());
	}

	template <typename T>
	unsigned int SmartStack<T>::GetCount() const
	{
		return mCapture.size();
	}
}