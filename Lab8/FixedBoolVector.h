#pragma once
#include <cstdint>
#include <cmath>
#include <cassert>
#include <iostream>

namespace lab8
{
	template <typename T, size_t N>
	class FixedVector;

	typedef uint32_t int_t;
	template <size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector()
			: mCount(0)
		{
			memset(mVector, 0, sizeof(int_t) * ((N + X) / BIT));
		}

		FixedVector(const FixedVector& rhs) = delete;
		FixedVector operator=(const FixedVector& other) = delete;
		~FixedVector() = default;

		bool Add(const bool& t)
		{
			if (mCount >= N)
			{
				return false;
			}

			mVector[mCount / BIT] |= static_cast<int_t>(t) << (mCount % BIT);

			++mCount;
			return true;
		}

		bool Remove(const bool& t)
		{

			bool bRemoved = false;
			int_t index = 0;
			while (index < mCount)
			{
				if (static_cast<bool>(mVector[index / BIT] & 0x1 << (index % BIT)) == t)
				{
					--mCount;
					bRemoved = true;
					break;
				}
				++index;
			}

			if (!bRemoved)
			{
				return false;
			}

			int_t& n = mVector[index / BIT];
			int_t back = n & static_cast<int_t>(std::pow(2, index % BIT) - 1);
			n = n >> (index % BIT + 1);
			n = n << (index % BIT);
			n |= back;

			Print();
			index /= BIT;
			for (unsigned int i = index; i < mCount / BIT; ++i)
			{
				mVector[i] &= 0x7FFFFFFF;
				mVector[i] = mVector[i] | ((mVector[i + 1] & 0x1) << X);
				mVector[i + 1] >>= 1;
			}
			Print();

			return true;
		}

		bool Get(int_t index) const
		{
			return mVector[index / BIT] & 0x1 << (index % BIT);
		}

		bool operator[](unsigned int index) const
		{
			return Get(index);
		}

		int GetIndex(const bool t) const
		{
			unsigned int index = 0;
			Print();
			while (index < mCount)
			{
				int_t b = mVector[index / BIT];
				if (static_cast<bool>(b & 0x1 << (index % BIT)) == t)
				{
					return index;
				}

				++index;
			}

			return -1;
		}

		size_t GetSize() const
		{
			return mCount;
		}
		size_t GetCapacity() const
		{
			return N;
		}

		void Print() const
		{
			for (unsigned int i = 0; i < 49; ++i)
			{
				if (i % 32 == 0)
				{
					std::cout << std::endl;
				}
				bool b = mVector[i / BIT] & 0x1 << (i % BIT);
				std::cout << b << ",";
			}

			std::cout << "---------------------------------------------------------------\n\n" << std::endl;
		}

	private:
		enum { BIT = 32, X = 31 };
		int_t mVector[(N + X) / BIT];
		size_t mCount;

	};
}