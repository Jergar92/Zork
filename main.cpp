#include "World.h"

int main(){
	char operation[100];
	char *ope;
	World a;
	//a.str->string= operation;

	a.createWorld();
	a.Help();
	printf("You are in %s, %s \n", a.player->location->name, a.player->location->description);
	while (1){
		//gets_s(operation, 100);
		a.str->Token(a.str->string, a.str->words);
		a.getOperation(a.str->words);

		if (a.str->words[0]== "quit"){
			break;
		}
	}
	
	return 0;
}
