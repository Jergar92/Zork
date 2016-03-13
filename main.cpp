#include "World.h"

int main(){
	char operation[10];
	bool doit = false;
	World a;
	a.createWorld();
	a.createExits();
	int i = 0, j = 0;
	printf("%s, %s \n", a.rooms[i].name, a.rooms[i].description);

	while (operation != "exit" || operation != "e"){
		doit = false;
		gets_s(operation, 10);
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
		else if (0 == strcmp(operation , "south")){
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
		else if (0 == strcmp(operation, "east")){
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
		else if (0 == strcmp(operation, "west")){
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

	system("pause");
	return 0;
}
