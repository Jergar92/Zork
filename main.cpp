#include "World.h"
#include "MemLeaks.h"


int main(){
	ReportMemoryLeaks();


	char operation[100];
	MyString words;
	World myWorld;

	myWorld.createWorld();
	myWorld.Help();
	myWorld.Look();


	while (1){
		Vector<MyString>strings;

		gets_s(operation, 100);
		words.Token(operation, strings);
		myWorld.getOperation(strings);
		if ((strings[0] == "quit")){
			break;
		}
		strings.clear();
	}

	return 0;

}

