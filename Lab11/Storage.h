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

		Storage(const Storage& rhs);
		Storage& operator=(const Storage& rhs);

		Storage(Storage&& rhs);
		Storage& operator=(Storage&& rhs);


		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;

	private:
		std::unique_ptr<T[]> mArray;
		size_t mCapacity;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		: mCapacity(length)
	{
		mArray = std::make_unique<T[]>(mCapacity);
		for (size_t i = 0; i < mCapacity; ++i)
		{
			memset(&mArray[0], 0, sizeof(T) * mCapacity);
		}
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
	Storage<T>::Storage(const Storage& rhs)
		: mCapacity(rhs.mCapacity)
	{
		mArray = std::make_unique<T[]>(rhs.mCapacity);
		for (size_t i = 0; i < mCapacity; ++i)
		{
			mArray[i] = rhs.mArray[i];
		}
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(const Storage& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		mCapacity = rhs.mCapacity;
		mArray = nullptr;
		mArray = std::make_unique<T[]>(mCapacity);
		
		for (size_t i = 0; i < mCapacity; ++i)
		{
			mArray[i] = rhs.mArray[i];
		}

		return *this;
	}

	template<typename T>
	Storage<T>::Storage(Storage&& rhs)
		: mCapacity(rhs.mCapacity)
	{
		mArray = std::move(rhs.mArray);
		rhs.mArray = nullptr;
		rhs.mCapacity = 0;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage&& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		mArray = std::move(rhs.mArray);
		mCapacity = rhs.mCapacity;
		rhs.mCapacity = 0;

		return *this;
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