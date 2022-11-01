#pragma once

#include <iostream>
#include <vector>
#include <map>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;

		typename std::vector<K>::const_iterator kIter = keys.begin();
		class std::vector<V>::const_iterator vIter = values.begin();

		while (kIter != keys.end() && vIter != values.end())
		{
			K key = *kIter;
			V value = *vIter;

			if (m.find(key) != m.end())
			{
				++kIter;
				continue;
			}
			m.insert(std::pair<K, V>(key, value));
			++kIter;
			++vIter;
		}

		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;

		for (typename std::map<K, V>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			v.push_back(iter->first);
		}

		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;

		for (typename std::map<K, V>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			v.push_back(iter->second);
		}

		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;

		for (auto iter = v.rbegin(); iter != v.rend(); ++iter)
		{
			rv.push_back(*iter);
		}

		return rv;
	}


	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> combined;
		for (typename std::vector<T>::const_iterator iter = v1.begin(); iter != v1.end(); ++iter)
		{
			for (auto c_iter = combined.begin(); c_iter != combined.end(); ++c_iter)
			{
				if (*c_iter == *iter)
				{
					goto next1;
				}
			}

			combined.push_back(*iter);
		next1: 
			;
		}

		for (typename std::vector<T>::const_iterator iter2 = v2.begin(); iter2 != v2.end(); ++iter2)
		{
			for (typename std::vector<T>::const_iterator iter1 = combined.begin(); iter1 != combined.end(); ++iter1)
			{
				if (*iter1 == *iter2)
				{
					goto next2;
				}
			}
			combined.push_back(*iter2);
		next2:
			;
		}

		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;

		for (typename std::map<K, V>::const_iterator iter = m1.begin(); iter != m1.end(); ++iter)
		{
			combined.insert(std::pair<K, V>(iter->first, iter->second));
		}

		for (typename std::map<K, V>::const_iterator iter = m2.begin(); iter != m2.end(); ++iter)
		{
			if (combined.find(iter->first) != combined.end())
			{
				continue;
			}
			combined.insert(*iter);
		}

		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		for (typename std::vector<T>::const_iterator iter = v.begin(); iter != v.end(); ++iter)
		{
			os << *iter;
			if (iter != v.end() - 1)
			{
				os << ", ";
			}
		}

		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		for (typename std::map<K, V>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			os << "{ " << iter->first << ", " << iter->second << " }" << std::endl;
		}

		return os;
	}
}