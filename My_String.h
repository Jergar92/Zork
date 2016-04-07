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
	bool Equals(const char* str1, const char* str2);
	void Set(char* str1, const char* str2);
	void Get();
	void Token(char* str, char* str2[]);
	void operator =(const MyString &other);
	bool operator ==(const char* str2)const;
	unsigned int MyStrlen()const;
private:

};



#endif // !_MY_STRING
