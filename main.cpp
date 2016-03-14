#include "World.h"
#define NUM_EXITS 24
int main(){
	char operation[10];
	//bool doit = false;
	World a;
	a.createWorld();
	a.createExits();
	int direction=-1, i = 0, j = 0;
	while (1){
		printf("%s, %s \n", a.player->location->name, a.player->location->description);
		gets_s(operation, 10);
		direction=a.getDirection(operation);
		for (i = 0; i < NUM_EXITS ; i++){

			if (0 == strcmp(a.exits[i].origin->name, a.player->location->name))
			{
				if (a.exits[i].direction == direction){
					a.player->location = a.exits[i].destination;
					break;
				}
			}
		}
	}
	/*	
		while (operation != "exit" || operation != "e"){

	doit = false;
		gets_s(operation, 10);
		if (0 == strcmp(operation, "look")){
			if (0 == strcmp(operation, "north") || 0 == strcmp(operation, "n")){
				for (j = 0; j < 13; j++){
					if (doit == false){
						if (0 == strcmp(a.rooms[i].side.north, a.rooms[j].name)){
							doit = true;
							a.rooms[j].description;
						}
					}
				}
			}
			else if (0 == strcmp(operation, "south") || 0 == strcmp(operation, "s")){
				for (j = 0; j < 13; j++){
					if (doit == false){
						if (0 == strcmp(a.rooms[i].side.south, a.rooms[j].name)){
							doit = true;
							a.rooms[j].description;
						}
					}
				}
			}
			else if (0 == strcmp(operation, "east") || 0 == strcmp(operation, "e")){
				for (j = 0; j < 13; j++){
					if (doit == false){
						if (0 == strcmp(a.rooms[i].side.east, a.rooms[j].name)){
							doit = true;
							a.rooms[j].description;
						}
					}
				}
			}
			else if (0 == strcmp(operation, "west") || 0 == strcmp(operation, "w")){
				for (j = 0; j < 13; j++){
					if (doit == false){
						if (0 == strcmp(a.rooms[i].side.west, a.rooms[j].name)){
							doit = true;
							a.rooms[j].description;
						}
					}
				}
			}
			else{
				printf("I don't understand you\n");
			}
		}
		else if (0 == strcmp(operation, "go")){
			if (0 == strcmp(operation, "north") || 0 == strcmp(operation, "n")){
				for (j = 0; j < 13; j++){
					if (doit == false){
						if (0 == strcmp(a.rooms[i].side.north, a.rooms[j].name)){
							if (a.rooms[j].closed == true){
								printf("the door is closed\n");
							}
							else{
								i = j;
								doit = true;
							}
						}
					}
				}
			}
			else if (0 == strcmp(operation, "south") || 0 == strcmp(operation, "s")){
				for (j = 0; j < 13; j++){
					if (doit == false){
						if (0 == strcmp(a.rooms[i].side.south, a.rooms[j].name)){
							if (a.rooms[j].closed == true){
								printf("the door is closed\n");
							}
							else{
								i = j;
								doit = true;
							}
						}
					}
				}
			}
			else if (0 == strcmp(operation, "east") || 0 == strcmp(operation, "e")){
				for (j = 0; j < 13; j++){
					if (doit == false){
						if (0 == strcmp(a.rooms[i].side.east, a.rooms[j].name)){
							if (a.rooms[j].closed == true){
								printf("the door is closed\n");
							}
							else{
								i = j;
								doit = true;
							}
						}
					}
				}
			}
			else if (0 == strcmp(operation, "west") || 0 == strcmp(operation, "w")){
				for (j = 0; j < 13; j++){
					if (doit == false){
						if (0 == strcmp(a.rooms[i].side.west, a.rooms[j].name)){
							if (a.rooms[j].closed == true){
								printf("the door is closed\n");
							}
							else{
								i = j;
								doit = true;
							}
						}
					}
				}
			}
			else{
				printf("I don't understand you\n");
			}
			if (doit == true){
				printf("%s, %s \n", a.rooms[i].name, a.rooms[i].description);
			}
		}
		else if (0 == strcmp(operation, "open")){
			if (0 == strcmp(operation, "north") || 0 == strcmp(operation, "n")){
				for (j = 0; j < 13; j++){
					if (doit == false){
						if (0 == strcmp(a.rooms[i].side.north, a.rooms[j].name)){
							doit = true;
							a.rooms[j].closed = true;
						}
					}
				}
			}
			else if (0 == strcmp(operation, "south") || 0 == strcmp(operation, "s")){
				for (j = 0; j < 13; j++){
					if (doit == false){
						if (0 == strcmp(a.rooms[i].side.south, a.rooms[j].name)){
							doit = true;
							a.rooms[j].closed = true;
						}
					}
				}
			}
			else if (0 == strcmp(operation, "east") || 0 == strcmp(operation, "e")){
				for (j = 0; j < 13; j++){
					if (doit == false){
						if (0 == strcmp(a.rooms[i].side.east, a.rooms[j].name)){
							doit = true;
							a.rooms[j].closed = true;
						}
					}
				}
			}
			else if (0 == strcmp(operation, "west") || 0 == strcmp(operation, "w")){
				for (j = 0; j < 13; j++){
					if (doit == false){
						if (0 == strcmp(a.rooms[i].side.west, a.rooms[j].name)){
							doit = true;
							a.rooms[j].closed = true;
						}
					}
				}
			}
			else{
				printf("I don't understand you\n");
			}
		}
	}

	*/
	system("pause");
	return 0;
}
