#include "MyString.h"
#include <cstdlib>

namespace assignment1
{
	MyString::MyString(const char* s)
		: length(0)
	{
		if (s == NULL || *s == '\0') {
			mStr = new char[length + 1];
			*mStr = '\0';
			return;
		}
		const char* s_ptr = s;
		char* str_ptr;
		while (*s_ptr != '\0') {
			length++;
			s_ptr++;
		}

		mStr = new char[length + 1];

		str_ptr = mStr;
		s_ptr = s;
		while (*s_ptr != '\0') {
			*str_ptr++ = *s_ptr++;
		}
		*str_ptr = '\0';
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
		if (s == NULL || isEmptyString(s)) {
			return;
		}

		const char* s_ptr = s;
		while (*s_ptr != '\0') {
			length++;
			s_ptr++;
		}

		char* str_temp = new char[length + 1];

		char* temp_ptr = str_temp;
		s_ptr = mStr;
		while (*s_ptr != '\0') {
			*temp_ptr++ = *s_ptr++;
		}
		s_ptr = s;
		while (*s_ptr != '\0') {
			*temp_ptr++ = *s_ptr++;
		}
		*temp_ptr = '\0';

		delete[] mStr;
		mStr = NULL;

		mStr = str_temp;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		char* temp = new char[length + other.length + 1];

		char* temp_ptr = temp;

		const char* str_ptr = mStr;

		while (*str_ptr != '\0') {
			*temp_ptr++ = *str_ptr++;
		}

		str_ptr = other.mStr;

		while (*str_ptr != '\0') {
			*temp_ptr++ = *str_ptr++;
		}

		*temp_ptr = '\0';

		MyString result = MyString(temp);

		delete[] temp;

		return result;
	}

	int MyString::IndexOf(const char* s)
	{
		if (s == NULL) {
			return -1;
		}

		if (isEmptyString(s)) {
			return 0;
		}
		const char* str_ptr = mStr;
		while (*str_ptr != '\0') {
			const char* s_ptr = s;
			int i = 0;
			while (*(str_ptr + i) == *(s_ptr + i)) {
				i++;
				if (*(s_ptr + i) == '\0') {
					return str_ptr - mStr;
				}
			}

			str_ptr++;
		}


		return -1;
	}

	int MyString::LastIndexOf(const char* s)
	{
		if (s == NULL) {
			return -1;
		}
		if (isEmptyString(s)) {
			return length;
		}
		const char* str_ptr = mStr;
		int index = -1;
		while (*str_ptr != '\0') {
			const char* s_ptr = s;
			int i = 0;
			while (*(str_ptr + i) == *s_ptr) {
				s_ptr++;
				if (*s_ptr == '\0') {
					index = str_ptr - mStr;
				}
				i++;
			}
			str_ptr++;
		}

		return index;
	}

	void MyString::Interleave(const char* s)
	{
		if (s == NULL || *s == '\0') {
			return;
		}

		const char* str_ptr = mStr;
		const char* s_ptr = s;
		char* pa_result;
		char* pa_result_ptr;
		unsigned int s_length = 0;

		while (*s_ptr++ != '\0') {
			s_length++;
		}
		s_ptr = s;

		pa_result = new char[length + s_length + 1];
		pa_result_ptr = pa_result;


		for (unsigned int i = 0; i < ((length > s_length) ? s_length : length) * 2; i++) {
			if (i % 2 == 0) {
				*pa_result_ptr++ = *str_ptr++;
			}
			else {
				*pa_result_ptr++ = *s_ptr++;
			}
		}
		const char* ptr = (length > s_length) ? str_ptr : s_ptr;

		while (*ptr != '\0') {
			*pa_result_ptr++ = *ptr++;
		}

		*pa_result_ptr = '\0';
		length += s_length;

		delete[] mStr;
		mStr = pa_result;
	}

	bool MyString::RemoveAt(unsigned int i)
	{
		char* str_ptr = mStr;

		if (i >= length) {
			return false;
		}
		for (unsigned int j = 0; j < length - i; j++) {
			*(str_ptr + i + j) = *(str_ptr + i + j + 1);
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
		if (this->length >= totalLength) {
			return;
		}

		char* result = new char[totalLength + 1];
		char* result_ptr = result;
		const char* str_ptr = mStr;

		for (unsigned int i = 0; i < totalLength; i++) {
			if (i < totalLength - this->length) {
				*result_ptr++ = c;
			}
			else {
				*result_ptr++ = *str_ptr++;
			}
		}
		*result_ptr = '\0';

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
		if (this->length > totalLength) {
			return;
		}

		char* result = new char[totalLength + 1];
		char* result_ptr = result;
		const char* str_ptr = mStr;

		for (unsigned int i = 0; i < totalLength; i++) {
			if (i < this->length) {
				*result_ptr++ = *str_ptr++;
			}
			else {
				*result_ptr++ = c;
			}
		}
		*result_ptr = '\0';

		delete[] mStr;
		mStr = result;
		this->length = totalLength;
	}

	void MyString::Reverse()
	{
		char* back_ptr = mStr + this->length;
		char* front_ptr = mStr;

		while (front_ptr < back_ptr) {
			char temp = *front_ptr;
			*front_ptr = *(back_ptr - 1);
			*(back_ptr - 1) = temp;

			back_ptr--;
			front_ptr++;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		const char* s1_ptr = mStr;
		const char* s2_ptr = rhs.mStr;

		while (*s1_ptr == *s2_ptr && *s1_ptr != '\0') {
			s1_ptr++;
			s2_ptr++;
		}

		return (*s1_ptr == '\0' && *s2_ptr == '\0') ? true : false;
	}

	bool MyString::operator==(const char* rhs) const {
		MyString myString(rhs);
		return this->operator==(myString);
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		if (*this == rhs) {
			return *this;
		}
		delete[] mStr;

		mStr = new char[rhs.length + 1];
		this->length = rhs.length;

		char* str_ptr = mStr;
		char* rhs_ptr = rhs.mStr;
		while (*rhs_ptr != '\0') {
			*str_ptr++ = *rhs_ptr++;
		}
		*str_ptr = '\0';

		return *this;
	}

	void MyString::ToLower()
	{
		char* str_ptr = mStr;

		while (*str_ptr != '\0') {
			if (*str_ptr >= 'A' && *str_ptr <= 'Z' || *str_ptr >= 'a' && *str_ptr <= 'z') {
				*str_ptr = *str_ptr | 0x20;
			}
			str_ptr++;
		}
	}

	void MyString::ToUpper()
	{
		char* str_ptr = mStr;

		while (*str_ptr != '\0') {
			if (*str_ptr >= 'A' && *str_ptr <= 'Z' || *str_ptr >= 'a' && *str_ptr <= 'z') {
				*str_ptr = *str_ptr & 0xDF;
			}
			str_ptr++;
		}
	}

	bool MyString::isEmptyString(const char* const str) const {
		if (*str == '\0') {
			return true;
		}
		return false;
	}
}