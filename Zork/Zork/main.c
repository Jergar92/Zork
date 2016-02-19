#include <stdio.h>
#include <stdlib.h>
#include "function.h"

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
