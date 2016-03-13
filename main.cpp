#include "World.h"

int main(){

	World a;
	a.createWorld();
	a.createExits();
	
	int i = 0, j = 0;
	
	printf("%s, %s \n", a.rooms[i].name, a.rooms[i].description);
	if (a.rooms[i].west != ""){
		for (j = 0; j < 13; j++){

			if (0 == strcmp(a.rooms[i].west, a.rooms[j].name)){
				i = j;
			}

		}
	}

printf("%s, %s \n", a.rooms[i].name, a.rooms[i].description);

	
	system("pause");
}
