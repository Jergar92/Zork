#include "World.h"
#include "My_String.h"

int main(){
	char operation[100];
	char *ope;
	ope = operation;
	World a;
	a.createWorld();
	a.Help();
	printf("You are in %s, %s \n", a.player->location->name, a.player->location->description);
	while (1){
		gets_s(operation, 100);
		a.str->Token(ope, a.str->words);
		a.getOperation(a.str->words);

		if (a.str->Equals(a.str->words[0], "quit")){
			break;
		}
	}
	
	return 0;
}
