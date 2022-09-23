#include "TimeSheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		:mName(name)
		, mMaxEntries(maxEntries)
		, mIndex(0)
	{
		mEntries = new int[mMaxEntries + 1];
		memset(mEntries, -1, sizeof(int) * (mMaxEntries + 1));
	}

	TimeSheet::TimeSheet(const TimeSheet& oth)
		:mName(oth.mName)
		, mMaxEntries(oth.mMaxEntries)
		, mIndex(oth.mIndex)
	{
		mEntries = new int[mMaxEntries + 1];
		memcpy(mEntries, oth.mEntries, sizeof(int) * (mMaxEntries + 1));
	}

	TimeSheet::~TimeSheet() {
		delete[] mEntries;
	}

	TimeSheet& TimeSheet::operator=(const TimeSheet& oth)
	{
		if (this == &oth) {
			return *this;
		}

		mName = oth.mName;
		mMaxEntries = oth.mMaxEntries;

		delete mEntries;

		mEntries = new int[mMaxEntries + 1];
		memcpy(mEntries, oth.mEntries, sizeof(int) * (mMaxEntries + 1));

		mIndex = oth.mIndex;

		return *this;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (mIndex >= mMaxEntries || timeInHours < MIN || timeInHours > MAX) {
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
		int* mEntries_ptr = mEntries;

		while (*mEntries_ptr != -1) {
			total += *mEntries_ptr++;
		}
		return total;
	}

	float TimeSheet::GetAverageTime() const
	{
		int totalTime = GetTotalTime();
		return (totalTime == 0) ? 0 : totalTime / (float)mIndex;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float val = 0.0f;
		int* mEntries_ptr = mEntries;
		while (*mEntries_ptr != -1) {
			val += (float)std::pow(*mEntries_ptr - GetAverageTime(), 2);
			mEntries_ptr++;
		}
		return (val == 0.0f) ? 0.0f : std::sqrt(val / mIndex);
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}
}