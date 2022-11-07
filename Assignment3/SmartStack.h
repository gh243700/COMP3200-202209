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
		SmartStack();
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
		T mSum;
		double mSumOfPow;
	};

	template <typename T>
	SmartStack<T>::SmartStack()
		: mSum(static_cast<T>(0))
		, mSumOfPow(0)
	{

	}

	template <typename T>
	SmartStack<T> SmartStack<T>::operator=(const SmartStack<T>& other)
	{
		if (this == &other)
		{
			return *this;
		}
		mSum = other.mSum;
		mCapture = other.mCapture;
		mSumOfPow = other.mSumOfPow;
		return *this;
	}

	template <typename T>
	bool SmartStack<T>::operator==(const SmartStack<T>& other)
	{
		if (this == &other)
		{
			return true;
		}

		return mCapture == other.mCapture && mSum == other.mSum && mSumOfPow == other.mSumOfPow;
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
		mSum += value;
		mSumOfPow += std::pow(static_cast<double>(value), 2);
		mCapture.push(Capture<T>(value, capture));
	}

	template<typename T>
	inline T SmartStack<T>::Pop()
	{
		assert(mCapture.size() != 0);

		T value = mCapture.top().GetValue();
		mSum -= value;
		mSumOfPow -= std::pow(static_cast<double>(value), 2);
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
			return std::numeric_limits<T>::lowest();
		}

		return mCapture.top().GetMax();
	}

	template <typename T>
	inline T SmartStack<T>::GetMin() const
	{
		if (mCapture.size() == 0)
		{
			return std::numeric_limits<T>::max();
		}

		return mCapture.top().GetMin();
	}

	template <typename T>
	inline double SmartStack<T>::GetAverage() const
	{
		if (mCapture.size() == 0)
		{
			return 0;
		}

		return mSum / static_cast<double>(mCapture.size());
	}

	template <typename T>
	inline T SmartStack<T>::GetSum() const
	{
		if (mCapture.size() == 0)
		{
			return 0;
		}

		return mSum;
	}

	template <typename T>
	inline double SmartStack<T>::GetVariance() const
	{
		Capture<T> capture = mCapture.top();
		double avg = GetAverage();
		return (mSumOfPow - 2 * avg * mSum + mCapture.size() * std::pow(avg, 2)) / static_cast<double>(mCapture.size());
	}

	template <typename T>
	inline double SmartStack<T>::GetStandardDeviation() const
	{
		return std::sqrt(static_cast<double>(GetVariance()));
	}

	template <typename T>
	unsigned int SmartStack<T>::GetCount() const
	{
		return mCapture.size();
	}
}