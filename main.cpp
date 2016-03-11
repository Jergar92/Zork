#include "World.h"

int main(){

	int num, numrand;
	char yn;
	string name;
	srand(time(NULL));

	World a;
	for (int i = 0; i < 13; i++){
		printf("%s\n", a.rooms[i].name);
	}
	system("pause");
}
