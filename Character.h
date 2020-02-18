// Character.h

#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct Storage Storage;

typedef struct Character Character;
struct Character {
	char *name;
	int health;
	int health_max;
	int hunger;
	int hunger_max;
	int thirst;
	int thirst_max;
	Storage *inventory;
};

bool isAlive(Character*);

#endif