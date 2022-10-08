#include "Person.h"

namespace assignment2
{
	Person::Person(const char* name, unsigned int weight)
		: mName(std::string(name))
		, mWeight(weight)
	{
	}

	Person::Person(const Person& other)
		: mName(std::string(other.mName))
		, mWeight(other.mWeight) 
	{
	}

	void Person::operator=(const Person& other)
	{
		mName = other.mName;
		mWeight = other.mWeight;
	}

	Person::~Person()
	{
	}

	bool Person::operator==(const Person& other)
	{
		if (this == &other || mName == other.mName && mWeight == other.mWeight)
		{
			return true;
		}

		return false;
	}

	const std::string& Person::GetName() const
	{
		return mName;
	}

	unsigned int Person::GetWeight() const
	{
		return mWeight;
	}
}