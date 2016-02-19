#include <stdio.h>
#include <stdlib.h>
#include "function.h"
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
				printf("On having gone down the rocks, you are next to the remains of your ship, but you hear noises coming from the cave");
				break;

			}
			if (myPosition.north == "homeBase") {
				myPosition = homeBase;
				printf("You are in a Home Base");
				break;

			}
			if (myPosition.north == "thornyPath") {
				printf("You are in a Thorny Path, you can feel as your skin it is torn while you cross, you cannot see anything except ways that are divided in all the directions");
				myPosition = thornyPath;
				break;

			}
		}
		break;
	case 's':
		if (myPosition.south != "nothing"){
			if (myPosition.south == "thornyPath") {
				myPosition = thornyPath;
				printf("You are in a Thorny Path, you can feel as your skin it is torn while you cross, you cannot see anything except ways that are divided in all the directions");
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
				printf("You find an underwater cave the ceiling of the cave have been destroyed by the impact of your ship probably\nin the background can clearly see a piece of your ship and antenna you need,\nbut you can see that with her is a beast like an eel");
				break;

			}
		}
		break;
	case 'w':
		if (myPosition.west != "nothing"){
			if (myPosition.west == "jungle") {
				myPosition = jungle;
				printf("You are in the jungle, you can hear many noises of beasts that you never heard,\nbecause you do not know if you can feed on vegetation on this planet\nyou will have to hunt the animals of this, the flesh is flesh");
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
				printf("You are in a large open area and on top you see a giant winged beast, and around you see a pile of bones,\nseems to be a kind of altar or where it eats this monster.");
				break;

			}
			if (myPosition.west == "waterfall") {
				myPosition = waterfall;
				printf("On having gone down the rocks, and you are on the front of the waterfall in the background can clearly see your robot AAR-88,\nif you could just stop the flow of the waterfall...");
				break;

			}
			if (myPosition.west == "gunPath") {
				myPosition = gunPath;
				printf("You are in a Gun Path");
				break;

			}
			if (myPosition.west == "thornyPath") {
				myPosition = thornyPath;
				printf("You are in a Thorny Path, you can feel as your skin it is torn while you cross, you cannot see anything except ways that are divided in all the directions");
				break;

			}
		}
		break;

	case 'e':
		if (myPosition.east != "nothing") {
			if (myPosition.east == "altar") {
				myPosition = altar;
				printf("You are in a large open area and on top you see a giant winged beast, and around you see a pile of bones,\nseems to be a kind of altar or where it eats this monster.");
				break;

			}
			if (myPosition.east == "waterfall") {
				myPosition = waterfall;
				printf("On having gone down the rocks, and you are on the front of the waterfall in the background can clearly see your robot AAR-88,\nif you could just stop the flow of the waterfall...");
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
				printf("You are in a Thorny Path, you can feel as your skin it is torn while you cross, you cannot see anything except ways that are divided in all the directions");
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