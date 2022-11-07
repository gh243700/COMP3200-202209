#pragma once
#include <cmath>
namespace assignment3
{
	template <typename T>
	class Capture
	{
	public:
		Capture();
		Capture(const T& value, const Capture& c);
		Capture operator=(const Capture& other);
		bool operator==(const Capture& other);
		~Capture() = default;

		T GetValue() const;
		T GetMin() const;
		T GetMax() const;

	private:
		T mValue;
		T mMax;
		T mMin;
	};

	template <typename T>
	inline Capture<T>::Capture()
		: mValue(static_cast<T>(0))
		, mMax(std::numeric_limits<T>::lowest())
		, mMin(std::numeric_limits<T>::max())
	{

	}

	template <typename T>
	inline Capture<T>::Capture(const T& value, const Capture& c)
		: mValue(value)
		, mMax((c.mMax < value) ? value : c.mMax)
		, mMin((c.mMin > value) ? value : c.mMin)
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

		return *this;
	}

	template <typename T>
	bool Capture<T>::operator==(const Capture<T>& other)
	{
		if (&other == this)
		{
			return true;
		}

		return mValue == other.mValue && mMax == other.mMax && mMin == other.mMin;
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
}
