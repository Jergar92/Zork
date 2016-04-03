#ifndef _MY_STRING
#define _MY_STRING
#include "World.h"

class My_String
{
public:	
	My_String(const char* str);
	My_String(const My_String &copy);
	unsigned int My_strlen()const;
	const char* C_Str()const;
	void Get();
	bool Empty()const;
	bool operator ==(const My_String &str)const;
	~My_String();
private:
	char *string = nullptr;

};
bool Equals(const My_String &str1, const char* str2);
void Set(char* str1, const char* str2);

#endif // !_MY_STRING
