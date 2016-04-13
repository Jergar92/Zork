#include "World.h"


MyString::MyString()
{
	maxCapacity = 1;
	string = new char[maxCapacity];
	*(string + 0) = '\0';
}
MyString::MyString(const char* str)
{
	int i;
	if (str != NULL){
		i = strlen(str) + 1;

		string = new char[i];
		printf("se ha creado un new\n");
		strcpy_s(string, i, str);
	}
	else{
		i = 0;
		string = nullptr;
	}
	maxCapacity = MyStrlen();
}
MyString::~MyString()
{
}


void MyString::Token(MyString &str, Vector<MyString> &strings){
	char* single = nullptr;
	char* save = nullptr;
	int i = 0;
	single = strtok_s(str.string, " ,.-", &save);
	while (single != NULL)
	{
		str.string = single;
		strings.push_back(str);
		single = strtok_s(NULL, " ,.-_", &save);
		i++;
	}
}
unsigned int MyString::MyStrlen()const{
	if (string != NULL){
		return strlen(string);
	}
	else{
		return 0;

	}
}
void MyString::operator=(const MyString &other){
	int primerlen = other.MyStrlen();
	if (maxCapacity >= primerlen){
		strcpy_s(string, maxCapacity, other.string);

	}
	else{
		delete[] string;
		string = new char[primerlen];
		maxCapacity = MyStrlen() + 1;
		strcpy_s(string, maxCapacity, other.string);
	}

}
void MyString::operator=(const char* str2){
	int capacity = strlen(str2) + 1;
		if (maxCapacity >= capacity){
		strcpy_s(string, maxCapacity, str2);

	}
	else{
		delete[] string;
		string = new char[capacity];
		maxCapacity = MyStrlen() + 1;
		strcpy_s(string, maxCapacity, str2);
	}

}
bool MyString::operator ==(const char* str2)const{
	return (0 == _stricmp(string, str2));
}
bool MyString::operator ==(const MyString &other)const{
	return (0 == _stricmp(string, other.string));
}

