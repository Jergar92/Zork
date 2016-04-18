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
	Vector<MyString>strings;


	while (1){
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

