#include "World.h"

MyString::MyString()
{
	maxCapacity = 1;
	buffer = new char[maxCapacity];
	*(buffer + 0) = '\0';
}
MyString::MyString(const char* str)
{
	int i;
	if (str != NULL){
		i = strlen(str);
		maxCapacity = i + 1;
		buffer = new char[maxCapacity];
		strcpy_s(buffer, maxCapacity, str);
	}
	else{
		i = 0;
		buffer = nullptr;
	}


}
MyString::~MyString()
{
	delete[]buffer;
}
void MyString::Token(char* str, Vector<MyString> &strings){
	char* single = nullptr;
	char* save = nullptr;
	int i = 0;
	single = strtok_s(str, " ,.-", &save);
	while (single != NULL)
	{
		strings.push_back(single);
		single = strtok_s(NULL, " ,.-_", &save);
		i++;
	}
}
unsigned int MyString::MyStrlen()const{
	return strlen(buffer);
}
void MyString::operator = (const MyString& other){
	int len = other.MyStrlen() + 1;
	if (maxCapacity <= len)
	{
		delete[] buffer;
		buffer = new char[len];
		maxCapacity = len;
	}
	strcpy_s(buffer, maxCapacity, other.buffer);

}
void MyString::operator=(const char* str2){
	int len = strlen(str2) + 1;
	if (maxCapacity <= len)
	{
		delete[] buffer;
		buffer = new char[len];
		maxCapacity = len;
	}
	strcpy_s(buffer, len, str2);
}

bool MyString::operator ==(const char* str2)const{
	return (0 == _stricmp(buffer, str2));
}
bool MyString::operator ==(const MyString &other)const{
	return (0 == _stricmp(buffer, other.buffer));
}
char* MyString::C_Str()const{
	return buffer;
}
