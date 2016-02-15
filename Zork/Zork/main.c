#include <stdio.h>
#include <stdlib.h>
typedef struct {
	char *north;
	char *south;
	char *west;
	char *east;
}side;
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
void movement(char dir) {
	switch (dir)
	{
	case 'n':
		if (myPosition.north != 'x') {
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
		if (myPosition.south != 'x') {
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
		if (myPosition.west != 'x') {
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
		if (myPosition.east != 'x') {
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
int main() {
	char direction = 'x';
	//////////////////////positions/////////////////
	homeBase.north = "rockPath";
	homeBase.south = "thornyPath";
	homeBase.west = "jungle";
	homeBase.east = "altar";

	rockPath.north = "monsterCave";
	rockPath.south = "homeBase";
	rockPath.west = "abandonedCave";
	rockPath.east = "waterfall";

	waterfall.north = 'x';
	waterfall.south = 'x';
	waterfall.west = "rockPath";
	waterfall.east = 'x';

	abandonedCave.north = 'x';
	abandonedCave.south = 'x';
	abandonedCave.west = 'x';
	abandonedCave.east = "rockPath";

	monsterCave.north = 'x';
	monsterCave.south = "rockPath";
	monsterCave.west = 'x';
	monsterCave.east = 'x';

	altar.north = 'x';
	altar.south = 'x';
	altar.west = "homeBase";
	altar.east ="bigNest";

	bigNest.north = 'x';
	bigNest.south = 'x';
	bigNest.west = "altar";
	bigNest.east = "rubble";

	rubble.north = 'x';
	rubble.south = 'x';
	rubble.west = "waterfall";
	rubble.east = 'x';

	thornyPath.north = "homeBase";
	thornyPath.south = "underwaterCave";
	thornyPath.west = "gunPath";
	thornyPath.east = "fuelPath";

	gunPath.north = 'x';
	gunPath.south = 'x';
	gunPath.west = 'x';
	gunPath.east = "thornyPath";

	fuelPath.north = 'x';
	fuelPath.south = 'x';
	fuelPath.west = "thornyPath";
	fuelPath.east = 'x';

	underwaterCave.north = "thornyPath";
	underwaterCave.south = 'x';
	underwaterCave.west = 'x';
	underwaterCave.east = 'x';

	gunPath.north = 'x';
	gunPath.south = 'x';
	gunPath.west = 'x';
	gunPath.east = "homeBase";
	////////////////////////////
	myPosition = homeBase;
	while (direction != 'q') {
		printf("\nWhich direction you want to go (n/s/e/w/q)? ");
		scanf_s(" %c", &direction);
		movement(direction);
		printf("\n\n");
	}
}
