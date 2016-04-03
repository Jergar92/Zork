#include "My_String.h"




bool Equals(const char* str1, const char* str2){
	return _stricmp(str1, str2) == 0;
}
void Set(char* str1, const char* str2){
	int i = strlen(str2) + 1;
	strcpy_s(str1, i, str2);
}
	char* single;
	char* save = NULL;
	int i = 0;		
	single = strtok_s(NULL, " ,.-", &save);
	while (single != NULL)
		{
		word[i] = single;
		single = strtok_s(NULL, " ,.-", &save);
		i++;
	}
}

