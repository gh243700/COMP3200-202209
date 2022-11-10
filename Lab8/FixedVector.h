#pragma once
#include <cstdint>
#include <cmath>
#include <cassert>
#include <iostream>
namespace lab8
{
	template <typename T, size_t N>
	class FixedVector final
	{
	public:
		FixedVector();
		FixedVector(const FixedVector& rhs) = default;
		~FixedVector() = default;
		bool Add(const T& t);
		bool Remove(const T& t);
		T Get(unsigned int index) const;
		T& operator[](unsigned int index);
		int GetIndex(const T& t) const;
		size_t GetSize() const;
		size_t GetCapacity() const;


	private:
		T mVector[N];
		size_t mCount;
	};

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector()
		: mCount(0)
	{
	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Add(const T& t)
	{
		if (mCount >= N)
		{
			return false;
		}

		mVector[mCount++] = t;
		return true;
	}

	template<typename T, size_t N>

	bool FixedVector<T, N>::Remove(const T& t)
	{
		size_t index = mCount;
		bool bRemoved = false;
		for (size_t i = 0; i < mCount; ++i)
		{
			if (mVector[i] == t)
			{
				index = i;
				bRemoved = true;
				--mCount;
				break;
			}
		}

		for (size_t i = index; i < mCount; ++i)
		{
			mVector[i] = mVector[i + 1];
		}

		return bRemoved;
	}

	template<typename T, size_t N>
	T FixedVector<T, N>::Get(unsigned int index) const
	{
		return mVector[index];
	}

	template<typename T, size_t N>
	T& FixedVector<T, N>::operator[](unsigned int index)
	{
		return mVector[index];
	}

	template<typename T, size_t N>
	int FixedVector<T, N>::GetIndex(const T& t) const
	{
		for (size_t i = 0; i < mCount; ++i)
		{
			if (mVector[i] == t)
			{
				return i;
			}
		}

		return -1;
	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetSize() const
	{
		return mCount;
	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity() const
	{
		return N;
	}



}