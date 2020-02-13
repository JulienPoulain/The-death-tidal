// Character.h

#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct Character Character;
struct Character {
	char *name;
	int health;
	int hunger;
	int thirst;
	Storage inventory;
};

#endif