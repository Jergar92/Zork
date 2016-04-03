#include "My_String.h"




My_String::My_String(const char* str)
{
	int i = strlen(str) + 1;
	string = new char[i];
	printf("se ha creado un new\n");

	strcpy_s(string, i, str);


}

My_String::My_String(const My_String &copy){
	
	int i = strlen(copy.string) + 1;
	if (i > 0){
		string = new char[i];
		printf("se ha creado un new\n");
		strcpy_s(string, i, copy.string);
	}
	else{
		i = 0;
		string = nullptr;
	}
}
unsigned int My_String::My_strlen()const{
	return strlen(string);
}
const char* My_String::C_Str()const {
	return string;
}
void My_String::Get(){

}
bool My_String::Empty()const{
	return string == "\0";
}
bool My_String::operator ==(const My_String &str)const{
	return (0 == strcmp(string, str.string));
}
bool Equals(const My_String &str1, const char* str2){
	return _stricmp(str1.C_Str(), str2) == 0;
}
void Set(char* str1, const char* str2){
	int i = strlen(str2) + 1;
	strcpy_s(str1, i, str2);
}

My_String::~My_String()
{
	printf("%s <-----se destruira\n", string);
	delete[] string;
	getchar();
}
