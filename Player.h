#ifndef _PLAYER
#define _PLAYER
#include "World.h"
class Room;

class Player
{
public:
	Room* location;
public:
	Player();
	~Player();
	void Go();
	void Look();
	void Open();
private:
};


#endif _PLAYER