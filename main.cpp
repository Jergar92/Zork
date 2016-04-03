#include "World.h"
#include "My_String.h"

int main(){

	char* words[10];
	char operation[20];
	char *ope;
	ope = operation;
	World a;
	a.createWorld();
	a.Help();
	printf("You are in %s, %s \n", a.player->location->name, a.player->location->description);
	while (1){
		gets_s(operation, 20);
		Token(ope, words);
		a.getOperation(words);

		if (Equals(words[0], "quit")){
			break;
		}
	}
	
	return 0;
}
