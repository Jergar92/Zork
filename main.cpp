#include "World.h"
#include "MemLeaks.h"


int main(){
	ReportMemoryLeaks();

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
		if ((strings[0] == "quit")){
			break;
		}
		strings.clear();
	}

	return 0;

}

