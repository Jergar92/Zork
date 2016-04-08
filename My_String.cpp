#include "World.h"


MyString::MyString()
{
	maxCapacity = 10;
	string = new char[maxCapacity];
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
unsigned int MyString::MyStrlen()const{
	if (string != NULL){
		return strlen(string);
	}
	else{
		return 0;

	}
}
void MyString::operator=(const MyString &other){
	int primerlen = other.MyStrlen() + 1;
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
	int primerlen = strlen(str2) + 1;
	if (maxCapacity >= primerlen){
		strcpy_s(string, primerlen, str2);

	}
	else{
		delete[] string;
		string = new char[primerlen];
		maxCapacity = MyStrlen() + 1;
		strcpy_s(string, primerlen, str2);
	}

}
bool MyString::operator ==(const char* str2)const{
	return (0 == _stricmp(string, str2));
}
bool MyString::operator ==(const MyString &other)const{
	return (0 == _stricmp(string, other.string));
}

const char* MyString::C_Words()const {
	return string;
}

