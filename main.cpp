#include "World.h"

int main(){

	World a;
	a.createWorld();
	a.createExits();

	int i = 0, j = 0;

	printf("%s, %s \n", a.rooms[i].name, a.rooms[i].description);
	for (j = 0; j < 13; j++){
		if (a.rooms[i].west == a.rooms[j].name){
			i = j;
		}
	}
printf("%s, %s \n", a.rooms[i].name, a.rooms[i].description);

	
	system("pause");
}
