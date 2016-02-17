#include <stdio.h>
#include <stdlib.h>
typedef struct {
	char *north;
	char *south;
	char *west;
	char *east;
}side;
void movement(char);
side myPosition;
side homeBase;
side rockPath;
side waterfall;
side abandonedCave;
side monsterCave;
side altar;
side bigNest;
side rubble;
side thornyPath;
side fuelPath;
side gunPath;
side underwaterCave;
side jungle;

int main(){
	//////////////////////positions/////////////////
	homeBase.north = "rockPath";
	homeBase.south = "thornyPath";
	homeBase.west = "jungle";
	homeBase.east = "altar";

	rockPath.north = "monsterCave";
	rockPath.south = "homeBase";
	rockPath.west = "abandonedCave";
	rockPath.east = "waterfall";

	waterfall.north = "nothing";
	waterfall.south = "nothing";
	waterfall.west = "rockPath";
	waterfall.east = "nothing";

	abandonedCave.north = "nothing";
	abandonedCave.south = "nothing";
	abandonedCave.west = "nothing";
	abandonedCave.east = "rockPath";

	monsterCave.north = "nothing";
	monsterCave.south = "rockPath";
	monsterCave.west = "nothing";
	monsterCave.east = "nothing";

	altar.north = "nothing";
	altar.south = "nothing";
	altar.west = "homeBase";
	altar.east = "bigNest";

	bigNest.north = "nothing";
	bigNest.south = "nothing";
	bigNest.west = "altar";
	bigNest.east = "rubble";

	rubble.north = "nothing";
	rubble.south = "nothing";
	rubble.west = "waterfall";
	rubble.east = "nothing";

	thornyPath.north = "homeBase";
	thornyPath.south = "underwaterCave";
	thornyPath.west = "gunPath";
	thornyPath.east = "fuelPath";

	gunPath.north = "nothing"; 
	gunPath.south = "nothing";
	gunPath.west = "nothing";
	gunPath.east = "thornyPath";

	fuelPath.north = "nothing";
	fuelPath.south = "nothing";
	fuelPath.west = "thornyPath";
	fuelPath.east = "nothing";

	underwaterCave.north = "thornyPath";
	underwaterCave.south = "nothing";
	underwaterCave.west = "nothing";
	underwaterCave.east = "nothing";

	jungle.north = "nothing";
	jungle.south = "nothing";
	jungle.west = "nothing";
	jungle.east = "homeBase";

	////////////////////////////
	myPosition = homeBase;
	char direction = 'x';

	while (direction != 'q') {
		printf("\nWhich direction you want to go (n/s/e/w/q)? ");
		scanf_s(" %c", &direction);
		movement(direction);
		printf("\n\n");
	}
}
void movement(char dir) {
	switch (dir)
	{
	case 'n':
		if (myPosition.north != "nothing") {
			if (myPosition.north == "rockPath") {
				myPosition = rockPath;
				printf("You are on a road with a large rock at the edge of a precipice,\non your left under a rocky road you see a cave apparently abandoned\nbottom right you see a waterfall and something seems to shine in it \nnorth from the top you see a large chunk of your ship near a cave");
				break;

			}
			if (myPosition.north == "monsterCave") {
				myPosition = monsterCave;
				printf("You are in a Monster Cave");
				break;

			}
			if (myPosition.north == "homeBase") {
				myPosition = homeBase;
				printf("You are in a Home Base");
				break;

			}
			if (myPosition.north == "thornyPath") {
				printf("You are in a Thorny Path");
				myPosition = thornyPath;
				break;

			}
		}
		break;
	case 's':
		if (myPosition.south != "nothing"){
			if (myPosition.south == "thornyPath") {
				myPosition = thornyPath;
				printf("You are in a Thorny Path");
				break;

			}
			if (myPosition.south == "homeBase") {
				myPosition = homeBase;
				printf("You are in a Home Base");
				break;

			}
			if (myPosition.south == "rockPath") {
				myPosition = rockPath;
				printf("You are on a road with a large rock at the edge of a precipice,\non your left under a rocky road you see a cave apparently abandoned\nbottom right you see a waterfall and something seems to shine in it \nnorth from the top you see a large chunk of your ship near a cave");
				break;

			}
			if (myPosition.south == "underwaterCave") {
				myPosition = underwaterCave;
				printf("You are in a Underwater Cave");
				break;

			}
		}
		break;
	case 'w':
		if (myPosition.west != "nothing"){
			if (myPosition.west == "jungle") {
				myPosition = jungle;
				printf("You are in a Jungle");
				break;

			}
			if (myPosition.west == "abandonedCave") {
				myPosition = abandonedCave;
				printf("You are in a Abandoned Cave");
				break;

			}
			if (myPosition.west == "rockPath") {
				myPosition = rockPath;
				printf("You are on a road with a large rock at the edge of a precipice,\non your left under a rocky road you see a cave apparently abandoned\nbottom right you see a waterfall and something seems to shine in it \nnorth from the top you see a large chunk of your ship near a cave");
				break;

			}
			if (myPosition.west == "homeBase") {
				myPosition = homeBase;
				printf("You are in a Home Base");
				break;

			}
			if (myPosition.west == "altar") {
				myPosition = altar;
				printf("You are in a Altar");
				break;

			}
			if (myPosition.west == "waterfall") {
				myPosition = waterfall;
				printf("You are in a Waterfall");
				break;

			}
			if (myPosition.west == "gunPath") {
				myPosition = gunPath;
				printf("You are in a Gun Path");
				break;

			}
			if (myPosition.west == "thornyPath") {
				myPosition = thornyPath;
				printf("You are in a Thorny Path");
				break;

			}
		}
		break;

	case 'e':
		if (myPosition.east != "nothing") {
			if (myPosition.east == "altar") {
				myPosition = altar;
				printf("You are in a Altar");
				break;

			}
			if (myPosition.east == "waterfall") {
				myPosition = waterfall;
				printf("You are in a Waterfall");
				break;

			}
			if (myPosition.east == "rockPath") {
				myPosition = rockPath;
				printf("You are in a Rock path");
				break;

			}
			if (myPosition.east == "bigNest") {
				myPosition = bigNest;
				printf("You are in a Big Nest");
				break;

			}
			if (myPosition.east == "rubble") {
				myPosition = rubble;
				printf("You are in a Rubble");
				break;

			}
			if (myPosition.east == "fuelPath") {
				myPosition = fuelPath;
				printf("You are in a Fuel Path");
				break;

			}
			if (myPosition.east == "thornyPath") {
				myPosition = thornyPath;
				printf("You are in a Thorny Path");
				break;

			}
			if (myPosition.east == "homeBase") {
				myPosition = homeBase;
				printf("You are in a Home Base");
				break;

			}
		}
		break;

	default:
		break;
	}
}