#pragma once

#include <memory>

namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		Storage(Storage&& ths);
		Storage& operator=(Storage&& ths);


		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;

	private:
		std::unique_ptr<T[]> mArray;
		size_t mCapacity;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		: Storage(length, 0)
	{
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mCapacity(length)
	{
		mArray = std::make_unique<T[]>(mCapacity);
		for (unsigned int i = 0; i < mCapacity; ++i)
		{
			mArray[i] = initialValue;
		}
	}

	template<typename T>
	Storage<T>::Storage(Storage&& ths)
		: mCapacity(ths.mCapacity)
	{
		mArray = std::move(ths.mArray);
		ths.mArray = nullptr;
		ths.mCapacity = 0;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage&& ths)
	{
		if (this == &ths)
		{
			return *this;
		}

		mArray = std::move(ths.mArray);
		mCapacity = ths.mCapacity;
		ths.mCapacity = 0;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index >= mCapacity)
		{
			return false;
		}

		mArray[index] = data;

		return true;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return mArray;
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mCapacity;
	}
}