#pragma once
#include<cmath>

#include<string>

#define MAX (10)
#define MIN (1)

namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries);
		TimeSheet(const TimeSheet& oth);
		~TimeSheet();
		TimeSheet& operator=(const TimeSheet& oth);
		void AddTime(int timeInHours);
		int GetTimeEntry(unsigned int index) const;
		int GetTotalTime() const;
		float GetAverageTime() const;
		float GetStandardDeviation() const;
		const std::string& GetName() const;


	private:
		// �ʿ信 ���� private ������ �޼��带 �߰��ϼ���.
		std::string mName;
		unsigned int mMaxEntries;
		int* mEntries;
		unsigned int mIndex;
	};
}
