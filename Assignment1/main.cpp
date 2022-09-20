#include "MyString.h"
#include <cassert>
#include <iostream>

void test_index_of();
void test_LastIndexOf();
void test_Interleave();
void test_RemoveAt();
void test_PadLeft();
void test_PadRight();
void test_Reverse();
void test10();
void test_11();
void no_malloc();
void test1();
void test2();
void test3();
void test4();

using namespace assignment1;
using namespace std;

int main()
{
	{
		assignment1::MyString my1("pope pope");
		std::string s1("pope pope");

		const char* cString = my1.GetCString();
		assignment1::MyString copied(my1);

		// E0, E1
		assert(my1.IndexOf("p") == s1.find("p"));
		assert(my1.LastIndexOf("p") == s1.rfind("p"));

		assert(my1.IndexOf("pop") == s1.find("pop"));
		assert(my1.LastIndexOf("pop") == s1.rfind("pop"));

		assert(my1.IndexOf("popen") == s1.find("popen"));

		assert(my1.LastIndexOf("popen") == s1.rfind("popen"));

		assert(my1.IndexOf("pope pope love") == s1.find("pope pope love"));
		assert(my1.LastIndexOf("pope pope love") == s1.rfind("pope pope love"));

		assert(my1.IndexOf(" pope") == s1.find(" pope"));
		assert(my1.LastIndexOf("pope ") == s1.rfind("pope "));
		cout << my1.IndexOf("") << " : " << s1.find("") << endl;
		// E2, E3
		assert(my1.IndexOf("") == s1.find(""));
		assert(my1.LastIndexOf("") == s1.rfind(""));

		// E4
		assert(my1 == copied);					// value
		assert(my1.GetCString() == cString);
	}


	assignment1::MyString s0 = assignment1::MyString("");


	const char* s1 = "Hello World!";

	assignment1::MyString s2 = assignment1::MyString(s1);

	assignment1::MyString s3 = assignment1::MyString(s2);
	s3.Append(" new");


	test_index_of();
	test_LastIndexOf();
	test_Interleave();
	test_RemoveAt();
	test_PadLeft();
	test_PadRight();
	test_Reverse();
	test10();
	test_11();
	no_malloc();
	test1();
	test2();
	test3();
	test4();

	cout << "TEST OVER" << endl;

}


void test_index_of() {
	assignment1::MyString s1 = assignment1::MyString("Hello World");

	assert(s1.IndexOf("ello") == 1);
	assert(s1.IndexOf("ellow") == -1);

}

void test_LastIndexOf() {
	assignment1::MyString s1 = "Hello World Hello World Hello World";

	int index = s1.LastIndexOf("Hello");

	std::cout << index << std::endl;
	assert(index == 24);
}


void test_Interleave() {
	assignment1::MyString s1 = "13579";
	assignment1::MyString s2 = "123456789";

	s1.Interleave("2468");

	assert(s1 == s2);
}

void test_RemoveAt() {
	assignment1::MyString s1 = "012345";

	assignment1::MyString s2 = "12345";
	assignment1::MyString s3 = "1234";

	assert(s1.RemoveAt(0) == true);
	assert(s1 == s2);
	assert(s1.RemoveAt(4) == true);
	assert(s1 == s3);
	assert(s1.RemoveAt(4) == false);
}

void test_PadLeft() {
	assignment1::MyString s1("Hello");

	s1.PadLeft(2); // s1: "Hello"
	assert(s1 == "Hello");

	s1.PadLeft(8); // s1: "   Hello"
	assert(s1 == "   Hello");

	assignment1::MyString s2("World");
	s2.PadLeft(3, '-'); // s2: "World"
	assert(s2 == "World");
	s2.PadLeft(7, '-'); // s2: "--World"
	assert(s2 == "--World");
}

void test_PadRight() {
	assignment1::MyString s1("Hello");

	s1.PadRight(2); // s1: "Hello"
	assert(s1 == "Hello");
	s1.PadRight(8); // s1: "Hello   "
	assert(s1 == "Hello   ");

	assignment1::MyString s2("World");
	s2.PadRight(3, '-'); // s2: "World";
	assert(s2 == "World");
	s2.PadRight(7, '-'); // s2: "World--"
	assert(s2 == "World--");
}


void test_Reverse() {
	assignment1::MyString s("Hello");
	s.Reverse(); // s: "olleH"
	assert(s == "olleH");

	assert(true);
}

void test10() {
	assignment1::MyString s1("Hello");
	assignment1::MyString s2(" World");

	assignment1::MyString s3 = s1 + s2; // s3는 "Hello World"가 되며, s1와 s2는 여전히 "Hello"와 " World"임
	assert(s3 == "Hello World");
}


void test_11() {
	assignment1::MyString s1("HEllo 123K");
	s1.ToLower(); // s1: "hello 123k"

	assert(s1 == "hello 123k");

	assignment1::MyString s2("HEllo 123K");
	s2.ToUpper(); // s1: "HELLO 123K"
	assert("HELLO 123K");
}

void no_malloc() {
	
}


void test1()
{
	std::string srcHi = "Hello, world!";
	std::string srcBye = "Bye, world!";
	std::string srcHiBye = srcHi + srcBye;
	std::string srcEmpty = "";

	MyString hi(srcHi.c_str());
	MyString hi2(hi);
	MyString empty(srcEmpty.c_str());

	assert(hi.GetLength() == srcHi.size());
	assert(hi2.GetLength() == srcHi.size());
	assert(empty.GetLength() == 0);

	assert(hi.GetCString() != srcHi.c_str());
	assert(hi2.GetCString() != srcHi.c_str());
	assert(hi.GetCString() != hi2.GetCString());
	assert(empty.GetCString() != srcEmpty.c_str());

	assert(strcmp(hi.GetCString(), srcHi.c_str()) == 0);
	assert(strcmp(hi2.GetCString(), srcHi.c_str()) == 0);
	assert(strcmp(empty.GetCString(), srcEmpty.c_str()) == 0);

	hi.Append(srcBye.c_str());
	assert(hi.GetLength() == srcHiBye.size());
	assert(strcmp(hi.GetCString(), srcHiBye.c_str()) == 0);

	hi2.Append(NULL);
	assert(hi2.GetLength() == srcHi.size());
	assert(strcmp(hi2.GetCString(), srcHi.c_str()) == 0);

	hi2.Append("");
	assert(hi2.GetLength() == srcHi.size());
	assert(strcmp(hi2.GetCString(), srcHi.c_str()) == 0);
}

void test2()
{
	std::string srcHi = "Hello, world!";
	std::string srcBye = "Bye, world!";
	std::string srcHiBye = srcHi + srcBye;

	MyString hi(srcHi.c_str());
	MyString bye(srcBye.c_str());
	MyString hiBye = hi + bye;
	MyString empty("");
	MyString hi2 = hi + empty;

	assert(strcmp(hi.GetCString(), srcHi.c_str()) == 0);
	assert(strcmp(bye.GetCString(), srcBye.c_str()) == 0);
	assert(strcmp(hiBye.GetCString(), srcHiBye.c_str()) == 0);
	assert(strcmp(hi2.GetCString(), srcHi.c_str()) == 0);
	assert(hi.GetLength() == srcHi.size());
	assert(bye.GetLength() == srcBye.size());
	assert(hiBye.GetLength() == srcHiBye.size());
	assert(hi2.GetLength() == srcHi.size());

	assert(hi.IndexOf(NULL) == -1);
	assert(hi.IndexOf("") == srcHi.find(""));
	assert(hi.IndexOf("l") == srcHi.find("l"));
	assert(hi.IndexOf("lo") == srcHi.find("lo"));
	assert(hi.IndexOf("ld") == srcHi.find("ld"));
	assert(hi.IndexOf("1234") == srcHi.find("1234"));
	assert(hi.IndexOf(", world!") == srcHi.find(", world!"));
	assert(hi.IndexOf("Hello, world!") == srcHi.find("Hello, world!"));

	assert(empty.IndexOf(NULL) == -1);
	assert(empty.IndexOf("") == 0);
	assert(empty.IndexOf("l") == -1);
	assert(empty.IndexOf("lo") == -1);
	assert(empty.IndexOf("ld") == -1);
	assert(empty.IndexOf("1234") == -1);
	assert(empty.IndexOf(", world!") == -1);
	assert(empty.IndexOf("Hello, world!") == -1);

	assert(hi.LastIndexOf(NULL) == -1);
	assert(hi.LastIndexOf("") == srcHi.rfind(""));
	assert(hi.LastIndexOf("l") == srcHi.rfind("l"));
	assert(hi.LastIndexOf("lo") == srcHi.rfind("lo"));
	assert(hi.LastIndexOf("ld") == srcHi.rfind("ld"));
	assert(hi.LastIndexOf("1234") == srcHi.rfind("1234"));
	assert(hi.LastIndexOf(", world!") == srcHi.rfind(", world!"));
	assert(hi.LastIndexOf("Hello, world!") == srcHi.rfind("Hello, world!"));
}

void test3()
{
	std::string srcAaa = "aaaaa";
	std::string srcBbb = "bbbbb";
	MyString aaa(srcAaa.c_str());
	MyString bbb(srcBbb.c_str());
	MyString empty("");

	empty.Interleave(NULL);
	assert(empty.GetLength() == 0);
	assert(strcmp(empty.GetCString(), "") == 0);

	empty.Interleave("");
	assert(empty.GetLength() == 0);
	assert(strcmp(empty.GetCString(), "") == 0);

	aaa.Interleave(NULL);
	assert(aaa.GetLength() == 5);
	assert(strcmp(aaa.GetCString(), "aaaaa") == 0);

	aaa.Interleave("");
	assert(aaa.GetLength() == 5);
	assert(strcmp(aaa.GetCString(), "aaaaa") == 0);

	aaa.Interleave(srcBbb.c_str());
	assert(aaa.GetLength() == 10);
	assert(strcmp(aaa.GetCString(), "ababababab") == 0);

	assert(!aaa.RemoveAt(UINT32_MAX));
	assert(aaa.GetLength() == 10);
	assert(strcmp(aaa.GetCString(), "ababababab") == 0);

	assert(aaa.RemoveAt(1));
	assert(aaa.GetLength() == 9);
	assert(strcmp(aaa.GetCString(), "aabababab") == 0);

	assert(aaa.RemoveAt(2));
	assert(aaa.GetLength() == 8);
	assert(strcmp(aaa.GetCString(), "aaababab") == 0);

	assert(aaa.RemoveAt(3));
	assert(aaa.GetLength() == 7);
	assert(strcmp(aaa.GetCString(), "aaaabab") == 0);

	assert(aaa.RemoveAt(4));
	assert(aaa.GetLength() == 6);
	assert(strcmp(aaa.GetCString(), "aaaaab") == 0);

	assert(aaa.RemoveAt(5));
	assert(aaa.GetLength() == 5);
	assert(strcmp(aaa.GetCString(), "aaaaa") == 0);

	aaa.PadLeft(0, '-');
	assert(aaa.GetLength() == 5);
	assert(strcmp(aaa.GetCString(), "aaaaa") == 0);

	aaa.PadLeft(5, '-');
	assert(aaa.GetLength() == 5);
	assert(strcmp(aaa.GetCString(), "aaaaa") == 0);

	aaa.PadLeft(10, '-');
	assert(aaa.GetLength() == 10);
	assert(strcmp(aaa.GetCString(), "-----aaaaa") == 0);

	bbb.PadRight(0, '-');
	assert(bbb.GetLength() == 5);
	assert(strcmp(bbb.GetCString(), "bbbbb") == 0);

	bbb.PadRight(5, '-');
	assert(bbb.GetLength() == 5);
	assert(strcmp(bbb.GetCString(), "bbbbb") == 0);

	bbb.PadRight(10, '-');
	assert(bbb.GetLength() == 10);
	assert(strcmp(bbb.GetCString(), "bbbbb-----") == 0);

	MyString nums("0123456789");
	nums.Reverse();
	assert(nums.GetLength() == 10);
	assert(strcmp(nums.GetCString(), "9876543210") == 0);
}

void test4()
{
	assert(MyString("") == MyString(""));
	assert(MyString("a") == MyString("a"));
	assert(!(MyString("a") == MyString("b")));
	assert(!(MyString(" ") == MyString("  ")));
	assert(MyString("ajweoifuj23q8o9ur2139y4i2u") == MyString("ajweoifuj23q8o9ur2139y4i2u"));
	assert(!(MyString("ajweoifuj23q8o9ur2139y4i2o") == MyString("ajweoifuj23q8o9ur2139y4i2u")));

	MyString mong("mong");
	MyString shell("shell");
	const char* mongOldStr = mong.GetCString();
	const char* shellOldStr = shell.GetCString();

	assert(!(mong == shell));
	assert(mong.GetLength() != shell.GetLength());
	assert(mong.GetCString() == mongOldStr);
	assert(mong.GetCString() != shell.GetCString());

	mong = shell;

	assert(mong == shell);
	assert(mong.GetLength() == shell.GetLength());
	
	assert(mong.GetCString() != shell.GetCString());

	assert(shell.GetCString() == shellOldStr);

	shell = shell;

	assert(shell.GetCString() == shellOldStr);

	MyString lowerCase("a bc;;def*g*hi_jk@");
	MyString upperCase("A BC;;DEF*G*HI_JK@");
	MyString mixedCase("a BC;;def*G*hI_Jk@");

	MyString case1 = lowerCase;
	MyString case2 = upperCase;
	MyString case3 = mixedCase;

	case1.ToLower();
	case2.ToLower();
	case3.ToLower();

	assert(case1 == lowerCase);
	assert(case2 == lowerCase);
	assert(case3 == lowerCase);

	case1 = lowerCase;
	case2 = upperCase;
	case3 = mixedCase;

	case1.ToUpper();
	case2.ToUpper();
	case3.ToUpper();

	assert(case1 == upperCase);
	assert(case2 == upperCase);
	assert(case3 == upperCase);
}
