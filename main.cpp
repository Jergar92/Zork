#include "World.h"

int main(){
	Vector<MyString>strings;

	char operation[100];
	MyString words;
	World a;
	a.createWorld();
	a.Help();
	while (1){
		gets_s(operation, 100);
		words = operation;
		words.Token(words, strings);
		a.getOperation(strings);
		strings.clear();

	/*	if ((strings[0] == "quit")){
			break;
		}*/
	}
	
	return 0;
}
