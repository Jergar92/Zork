#ifndef _WORLD
#define _WORLD

#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <string>
#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Entity.h"
#include "My_String.h"
class MyString; 

class World
{
public:
	Room* rooms = nullptr;
	Exit* exits = nullptr;
	Player* player = nullptr;
	MyString* str=nullptr;
public:
	World();
	~World();
<<<<<<< HEAD

	void createWorld() const;//this is called on main
	void Help();//this is called on main
	void getOperation(char* words[]);

private:
	int getDirection(char operation[]);
	void Go(char *words[]);
	void Look(char *words[]);
	void Open(char *words[]);
	void Close(char *words[]);
private:

=======
	void createWorld() const;
	void createExits() const;
	void Torken(char operation[]);
	void Help(char operation[])const;
private:
	int getDirection(char operation[]);
	void getOperation(char ope[], char ope2[]);
	void Go(char operation[]);
	void Look(char operation[]);
	void Open(char operation[]);
	void Close(char operation[]);
>>>>>>> origin/master
};

#endif _WORLD
