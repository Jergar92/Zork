#include "World.h"

int main(){
	Vector<MyString>strings;

	char operation[100];
	MyString words;
	World a;

	a.createWorld();
	a.Help();
	a.Look();

	while (1){
		Vector<MyString>strings;
		gets_s(operation, 100);
		words.Token(operation, strings);
		a.getOperation(strings);
		strings.clear();

		//	if ((strings == "quit")){
		//	break;
		//}
	}

	return 0;
}

