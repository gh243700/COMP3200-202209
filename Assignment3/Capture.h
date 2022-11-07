#pragma once
#include <cmath>

template <typename T>
class Capture
{
public:
	Capture();
	Capture(const T& value, const Capture& c);
	Capture operator=(const Capture& other);
	bool operator==(const Capture& other);

	T GetValue() const;
	T GetMin() const;
	T GetMax() const;
	T GetSum() const;
	T GetSumOfPow() const;

private:
	T mValue;
	T mMax;
	T mMin;
	T mSum;
	T mSumOfPow;
};

template <typename T>
inline Capture<T>::Capture()
	: mValue(static_cast<T>(0))
	, mMax(std::numeric_limits<T>::min())
	, mMin(std::numeric_limits<T>::max())
	, mSum(static_cast<T>(0))
	, mSumOfPow(static_cast<T>(0))
{

}

template <typename T>
inline Capture<T>::Capture(const T& value, const Capture& c)
	: mValue(value)
	, mMax((c.mMax < value) ? value : c.mMax)
	, mMin((c.mMin > value) ? value : c.mMin)
	, mSum(c.mSum + value)
	, mSumOfPow(c.mSumOfPow + static_cast<T>(std::pow(value, 2)))
{
}

template <typename T>
inline Capture<T> Capture<T>::operator=(const Capture<T>& other)
{
	if (this == &other)
	{
		return *this;
	}
	mValue = other.mValue;
	mMax = other.mMax;
	mMin = other.mMin;
	mSum = other.mSum;
	mSumOfPow = other.mSumOfPow;

	return *this;
}

template <typename T>
bool Capture<T>::operator==(const Capture<T>& other)
{
	if (&other == this)
	{
		return true;
	}

	return mValue == other.mValue && mMax == other.mMax && mMin == other.mMin && mSum == other.mSum && mSumOfPow == other.mSumOfPow;
}

template <typename T>
inline T Capture<T>::GetValue() const
{
	return mValue;
}

template <typename T>
inline T Capture<T>::GetMin() const
{
	return mMin;
}

template <typename T>
inline T Capture<T>::GetMax() const
{
	return mMax;
}

template <typename T>
inline T Capture<T>::GetSum() const
{
	return mSum;
}

template <typename T>
inline T Capture<T>::GetSumOfPow() const
{
	return mSumOfPow;
}