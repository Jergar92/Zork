#ifndef _ZORK_
#define _ZORK_

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



void movement(char);


#endif _ZORK_