#include <queue>
#include <limits>
#include <cmath>
#include <cassert>

namespace assignment3
{
	template <typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		SmartQueue(const SmartQueue& rhs) = default;
		SmartQueue operator=(const SmartQueue& rhs);

		~SmartQueue() = default;
		bool operator==(const SmartQueue& other);


		void Enqueue(const T& number);
		T Peek() const;
		T Dequeue();
		T GetMax() const;
		T GetMin() const;
		double GetAverage() const;
		T GetSum() const;
		double GetVariance() const;
		double GetStandardDeviation() const;
		unsigned int GetCount() const;

	private:
		std::queue<T> mValues;
		T mSum;
		T mSumOfPow;
	};

	template <typename T>
	SmartQueue<T>::SmartQueue()
		: mSum(static_cast<T>(0))
		, mSumOfPow(static_cast<T>(0))
	{

	}
	
	template <typename T>
	SmartQueue<T> SmartQueue<T>::operator=(const SmartQueue<T>& other)
	{
		if (this == &other)
		{
			return *this;
		}

		mValues = other.mValues;
		mSum = other.mSum;
		mSumOfPow = other.mSumOfPow;

		return *this;
	}


	template <typename T>
	bool SmartQueue<T>::operator==(const SmartQueue<T>& other)
	{
		if (this == &other)
		{
			return true;
		}

		return mValues == other.mValues && mSum == other.mSum && mSumOfPow == other.mSumOfPow;
	}



	template <typename T>
	void SmartQueue<T>::Enqueue(const T& number)
	{
		mValues.push(number);
		mSum += number;
		mSumOfPow += static_cast<T>(std::pow(number, 2));
	}

	template <typename T>
	T SmartQueue<T>::Peek() const
	{
		assert(mValues.size() > 0);
		return mValues.front();
	}

	template <typename T>
	T SmartQueue<T>::Dequeue()
	{
		assert(mValues.size() > 0);
		T value = mValues.front();
		mSum -= value;
		mSumOfPow -= static_cast<T>(std::pow(value, 2));
		mValues.pop();

		return value;
	}

	template <typename T>
	T SmartQueue<T>::GetMax() const
	{
		if (mValues.size() == 0)
		{
			return std::numeric_limits<T>::min();
		}

		std::queue<T> copy = mValues;
		T max = copy.front();
		copy.pop();
		while (copy.size() != 0)
		{
			if (max < copy.front())
			{
				max = copy.front();
			}
			copy.pop();
		}

		return max;
	}

	template <typename T>
	T SmartQueue<T>::GetMin() const
	{
		if (mValues.size() == 0)
		{
			return std::numeric_limits<T>::max();
		}

		std::queue<T> copy = mValues;
		T min = copy.front();
		copy.pop();

		while (copy.size() != 0)
		{
			if (min > copy.front())
			{
				min = copy.front();
			}
			copy.pop();
		}

		return min;
	}

	template <typename T>
	double SmartQueue<T>::GetAverage() const
	{
		assert(mValues.size() > 0);
		return mSum / static_cast<double>(mValues.size());
	}

	template <typename T>
	T SmartQueue<T>::GetSum() const
	{
		return mSum;
	}

	template <typename T>
	double SmartQueue<T>::GetVariance() const
	{
		assert(mValues.size() > 0);
		double avarage = GetAverage();
		return (mSumOfPow - 2 * avarage * mSum + mValues.size() * std::pow(avarage, 2)) / static_cast<double>(mValues.size());

	}

	template <typename T>
	double SmartQueue<T>::GetStandardDeviation() const
	{
		assert(mValues.size() > 0);
		return std::sqrt(GetVariance());
	}

	template <typename T>
	unsigned int SmartQueue<T>::GetCount() const
	{
		return mValues.size();
	}
}