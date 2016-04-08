#ifndef _MY_STRING
#define _MY_STRING
#include "World.h"
class MyString
{
public:
	char* string;
	char* words[10];
	int maxCapacity = 0;
public:
	MyString();
	MyString(const char* str);
	~MyString();
	const char* C_Words()const;

	void Token(char* str, char* str2[]);
	void operator =(const MyString &other);
	void operator =(const char* str2);
	bool operator ==(const char* str2)const;
	bool operator ==(const MyString &other)const;

	unsigned int MyStrlen()const;
private:

};



#endif // !_MY_STRING
