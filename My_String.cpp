#include "My_String.h"


MyString::MyString()
{
}

MyString::~MyString()
{
}


bool MyString::Equals(const char* str1, const char* str2){
	return _stricmp(str1, str2) == 0;
}
void MyString::Set(char* str1, const char* str2){
	int i = strlen(str2) + 1;
	strcpy_s(str1, i, str2);
}
void MyString::Token(char* str, char* word[]){
	char* single=nullptr;
	char* save = nullptr;
	int i = 0;		
	single = strtok_s(str, " ,.-", &save);
	while (single != NULL)
		{
		word[i] = single;
		single = strtok_s(NULL, " ,.-_", &save);
		i++;
	}
	while (i<10)
	{
		word[i] = "x";
		i++;
	}
}

