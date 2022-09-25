#include "TimeSheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		: mName(name)
		, mMaxEntries(maxEntries)
		, mIndex(0)
	{
		mEntries = new int[mMaxEntries + 1];
		memset(mEntries, -1, sizeof(int) * (mMaxEntries + 1));
	}

	TimeSheet::TimeSheet(const TimeSheet& oth)
		: mName(oth.mName)
		, mMaxEntries(oth.mMaxEntries)
		, mIndex(oth.mIndex)
	{
		mEntries = new int[mMaxEntries + 1];
		memcpy(mEntries, oth.mEntries, sizeof(int) * (mMaxEntries + 1));
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mEntries;
	}

	TimeSheet& TimeSheet::operator=(const TimeSheet& oth)
	{
		if (this == &oth)
		{
			return *this;
		}

		mName = oth.mName;
		mMaxEntries = oth.mMaxEntries;

		int* temp = new int[mMaxEntries + 1];
		memcpy(temp, oth.mEntries, sizeof(int) * (mMaxEntries + 1));

		delete[] mEntries;
		mEntries = temp;

		mIndex = oth.mIndex;

		return *this;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (mIndex >= mMaxEntries || timeInHours < MIN || timeInHours > MAX)
		{
			return;
		}

		mEntries[mIndex++] = timeInHours;
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		return (index >= mIndex) ? -1 : mEntries[index];
	}

	int TimeSheet::GetTotalTime() const
	{
		unsigned int total = 0;
		int* mEntriesPtr = mEntries;

		while (*mEntriesPtr != -1)
		{
			total += *mEntriesPtr++;
		}
		return total;
	}

	float TimeSheet::GetAverageTime() const
	{
		int totalTime = GetTotalTime();
		return (totalTime == 0) ? 0 : totalTime / static_cast<float>(mIndex);
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float val = 0.0f;
		int* mEntriesPtr = mEntries;
		while (*mEntriesPtr != -1)
		{
			val += static_cast<float>(std::pow(*mEntriesPtr - GetAverageTime(), 2));
			mEntriesPtr++;
		}
		return (val == 0.0f) ? 0.0f : std::sqrt(val / mIndex);
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}
}