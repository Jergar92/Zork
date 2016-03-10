#ifndef _EXIT
#define _EXIT
#include "World.h"


class Exit
{
public:
	Exit();
	~Exit();

private:
	struct{
		char *north;
		char *south;
		char *west;
		char *east;
	}exit;

};





#endif _EXIT