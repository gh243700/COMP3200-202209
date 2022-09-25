#include "MyString.h"
#include <cstdlib>

namespace assignment1
{
	MyString::MyString(const char* s)
		: length(0)
	{
		if (s == NULL || *s == '\0') 
		{
			mStr = new char[length + 1];
			*mStr = '\0';
			return;
		}
		const char* S_PTR = s;
		while (*S_PTR != '\0') 
		{
			length++;
			S_PTR++;
		}

		mStr = new char[length + 1];

		char* strPtr = mStr;
		S_PTR = s;
		while (*S_PTR != '\0') 
		{
			*strPtr++ = *S_PTR++;
		}
		*strPtr = '\0';
	}

	MyString::MyString(const MyString& other)
		: MyString(other.mStr)
	{
	}

	MyString::~MyString()
	{
		delete[] mStr;
	}

	unsigned int MyString::GetLength() const
	{
		return length;
	}

	const char* MyString::GetCString() const
	{
		return mStr;
	}

	void MyString::Append(const char* s)
	{
		if (s == NULL || isEmptyString(s)) 
		{
			return;
		}

		const char* S_PTR = s;
		while (*S_PTR != '\0') 
		{
			length++;
			S_PTR++;
		}

		char* strTemp = new char[length + 1];

		char* tempPtr = strTemp;
		S_PTR = mStr;
		while (*S_PTR != '\0') 
		{
			*tempPtr++ = *S_PTR++;
		}
		S_PTR = s;
		while (*S_PTR != '\0') 
		{
			*tempPtr++ = *S_PTR++;
		}
		*tempPtr = '\0';

		delete[] mStr;
		mStr = NULL;

		mStr = strTemp;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		char* temp = new char[length + other.length + 1];

		char* tempPtr = temp;

		const char* STR_PTR = mStr;

		while (*STR_PTR != '\0') 
		{
			*tempPtr++ = *STR_PTR++;
		}

		STR_PTR = other.mStr;

		while (*STR_PTR != '\0') 
		{
			*tempPtr++ = *STR_PTR++;
		}

		*tempPtr = '\0';

		MyString result = MyString(temp);

		delete[] temp;

		return result;
	}

	int MyString::IndexOf(const char* s)
	{
		if (s == NULL) 
		{
			return -1;
		}

		if (isEmptyString(s)) 
		{
			return 0;
		}
		const char* STR_PTR = mStr;
		while (*STR_PTR != '\0') 
		{
			const char* S_PTR = s;
			int i = 0;
			while (*(STR_PTR + i) == *(S_PTR + i)) 
			{
				i++;
				if (*(S_PTR + i) == '\0') 
				{
					return STR_PTR - mStr;
				}
			}

			STR_PTR++;
		}


		return -1;
	}

	int MyString::LastIndexOf(const char* s)
	{
		if (s == NULL) 
		{
			return -1;
		}
		if (isEmptyString(s)) 
		{
			return length;
		}
		const char* STR_PTR = mStr;
		int index = -1;
		while (*STR_PTR != '\0') 
		{
			const char* S_PTR = s;
			int i = 0;
			while (*(STR_PTR + i) == *S_PTR) 
			{
				S_PTR++;
				if (*S_PTR == '\0') 
				{
					index = STR_PTR - mStr;
				}
				i++;
			}
			STR_PTR++;
		}

		return index;
	}

	void MyString::Interleave(const char* s)
	{
		if (s == NULL || *s == '\0') 
		{
			return;
		}

		const char* STR_PTR = mStr;
		const char* S_PTR = s;
		char* paResult;
		char* paResultPtr;
		unsigned int sLength = 0;

		while (*S_PTR++ != '\0') 
		{
			sLength++;
		}
		S_PTR = s;

		paResult = new char[length + sLength + 1];
		paResultPtr = paResult;


		for (unsigned int i = 0; i < ((length > sLength) ? sLength : length) * 2; i++) 
		{
			if (i % 2 == 0) 
			{
				*paResultPtr++ = *STR_PTR++;
			}
			else 
			{
				*paResultPtr++ = *S_PTR++;
			}
		}
		const char* ptr = (length > sLength) ? STR_PTR : S_PTR;

		while (*ptr != '\0') 
		{
			*paResultPtr++ = *ptr++;
		}

		*paResultPtr = '\0';
		length += sLength;

		delete[] mStr;
		mStr = paResult;
	}

	bool MyString::RemoveAt(unsigned int i)
	{
		char* strPtr = mStr;

		if (i >= length) 
		{
			return false;
		}
		for (unsigned int j = 0; j < length - i; j++) 
		{
			*(strPtr + i + j) = *(strPtr + i + j + 1);
		}

		length--;
		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		PadLeft(totalLength, ' ');
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (this->length >= totalLength) 
		{
			return;
		}

		char* result = new char[totalLength + 1];
		char* resultPtr = result;
		const char* strPtr = mStr;

		for (unsigned int i = 0; i < totalLength; i++) 
		{
			if (i < totalLength - this->length) {
				*resultPtr++ = c;
			}
			else 
			{
				*resultPtr++ = *strPtr++;
			}
		}
		*resultPtr = '\0';

		this->length = totalLength;
		delete[] this->mStr;
		this->mStr = result;
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		PadRight(totalLength, ' ');
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (this->length > totalLength) 
		{
			return;
		}

		char* result = new char[totalLength + 1];
		char* resultPtr = result;
		const char* STR_PTR = mStr;

		for (unsigned int i = 0; i < totalLength; i++) 
		{
			if (i < this->length) 
			{
				*resultPtr++ = *STR_PTR++;
			}
			else 
			{
				*resultPtr++ = c;
			}
		}
		*resultPtr = '\0';

		delete[] mStr;
		mStr = result;
		this->length = totalLength;
	}

	void MyString::Reverse()
	{
		char* backPtr = mStr + this->length;
		char* frontPtr = mStr;

		while (frontPtr < backPtr) 
		{
			char temp = *frontPtr;
			*frontPtr = *(backPtr - 1);
			*(backPtr - 1) = temp;

			backPtr--;
			frontPtr++;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		const char* S1_PTR = mStr;
		const char* S2_PTR = rhs.mStr;

		while (*S1_PTR == *S2_PTR && *S1_PTR != '\0') 
		{
			S1_PTR++;
			S2_PTR++;
		}

		return (*S1_PTR == '\0' && *S2_PTR == '\0') ? true : false;
	}

	bool MyString::operator==(const char* rhs) const 
	{
		MyString myString(rhs);
		return this->operator==(myString);
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		if (*this == rhs) 
		{
			return *this;
		}
		delete[] mStr;

		mStr = new char[rhs.length + 1];
		this->length = rhs.length;

		char* strPtr = mStr;
		char* rhsPtr = rhs.mStr;
		while (*rhsPtr != '\0') 
		{
			*strPtr++ = *rhsPtr++;
		}
		*strPtr = '\0';

		return *this;
	}

	void MyString::ToLower()
	{
		char* strPtr = mStr;

		while (*strPtr != '\0') 
		{
			if (*strPtr >= 'A' && *strPtr <= 'Z' || *strPtr >= 'a' && *strPtr <= 'z') 
			{
				*strPtr = *strPtr | 0x20;
			}
			strPtr++;
		}
	}

	void MyString::ToUpper()
	{
		char* strPtr = mStr;

		while (*strPtr != '\0') 
		{
			if (*strPtr >= 'A' && *strPtr <= 'Z' || *strPtr >= 'a' && *strPtr <= 'z') 
			{
				*strPtr = *strPtr & 0xDF;
			}
			strPtr++;
		}
	}

	bool MyString::isEmptyString(const char* const str) const 
	{
		if (*str == '\0') 
		{
			return true;
		}
		return false;
	}
}