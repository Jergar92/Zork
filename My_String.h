#ifndef _MY_STRING
#define _MY_STRING
#include "World.h"
#include "My_Vector.h"

class MyString
{
public:
	char* buffer;
	int maxCapacity = 0;
public:
	MyString();
	MyString(const char* str);
	~MyString();

	void Token(char* str, Vector<MyString> &strings);
	void operator =(const MyString &other);
	void operator =(const char* str2);
	bool operator ==(const char* str2)const;
	bool operator ==(const MyString &other)const;

	unsigned int MyStrlen()const;
private:

};



#endif // !_MY_STRING
