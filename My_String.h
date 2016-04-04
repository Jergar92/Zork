#ifndef _MY_STRING
#define _MY_STRING
#include "World.h"
class MyString
{
public: 	
	char* words[10];

public:
	MyString();
	~MyString();
	bool Equals(const char* str1, const char* str2);
	void Set(char* str1, const char* str2);
	void Token(char* str, char* str2[]);
private:

};



#endif // !_MY_STRING
