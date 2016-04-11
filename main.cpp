#include "World.h"

int main(){
	char operation[100];
	MyString words;
	MyString strings[5];
	World a;
	a.createWorld();
	a.Help();
	printf("You are in %s, %s \n", a.player->location->name->string, a.player->location->description->string);
	while (1){
		gets_s(operation, 100);
		words = operation;
		words.Token(words, strings);
		a.getOperation(strings);

		if ((strings[0] == "quit")){
			break;
		}
	}
	
	return 0;
}
