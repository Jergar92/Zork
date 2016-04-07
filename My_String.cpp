#include "My_String.h"


MyString::MyString()
{
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
unsigned int MyString::MyStrlen()const{
	if (string != NULL){
		return strlen(string) + 1;
	}
	else{
		return 0;

	}
}
void MyString::operator=(const MyString &other){
	int primerlen = other.MyStrlen();
	if (maxCapacity >= primerlen){
		strcpy_s(string, primerlen, other.string);

	}
	else{
		delete[] string;
		string = new char[primerlen];
		maxCapacity = MyStrlen();
		strcpy_s(string, primerlen, other.string);
	}

}
bool MyString::operator ==(const char* str2)const{
	return (0 == _stricmp(string, str2));
}
void MyString::Get(){
	char operation[100];
	gets_s(operation, 100);
	string = operation;
}
const char* MyString::C_Words()const {
	return string;
}

