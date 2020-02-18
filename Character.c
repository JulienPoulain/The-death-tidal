// Character.c

#include <stdlib.h>
#include <stdbool.h>

#include "Character.h"

bool isAlive(Character *character) {
	return character->health >= 0;
}