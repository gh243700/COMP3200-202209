#pragma once
#include <queue>

namespace lab9
{
	template <typename T>
	class ObjectPool
	{
	public :
		ObjectPool(size_t maxPoolSize);
		ObjectPool(const ObjectPool& rhs) = delete;
		ObjectPool operator=(const ObjectPool& rhs) = delete;
		~ObjectPool();

		T* Get();
		void Return(T* ptr);
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();

	private:
		std::queue<T*> mObjectPool;
		const size_t M_MAX_POOL_SIZE;
	};

	template <typename T>
	ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: M_MAX_POOL_SIZE(maxPoolSize)
	{
	}

	template <typename T>
	ObjectPool<T>::~ObjectPool()
	{
		while (mObjectPool.size() != 0)
		{
			delete mObjectPool.front();
			mObjectPool.pop();
		}
	}

	template <typename T>
	T* ObjectPool<T>::Get()
	{
		if (mObjectPool.size() == 0)
		{
			return new T;
		}

		T* ptr = mObjectPool.front();
		mObjectPool.pop();

		return ptr;
	}


	template <typename T>
	void ObjectPool<T>::Return(T* ptr)
	{
		if (mObjectPool.size() >= M_MAX_POOL_SIZE)
		{
			delete ptr;
			return;
		}

		mObjectPool.push(ptr);
	}

	template <typename T>
	size_t ObjectPool<T>::GetFreeObjectCount()
	{
		return mObjectPool.size();
	}

	template <typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount()
	{
		return M_MAX_POOL_SIZE;
	}
}


