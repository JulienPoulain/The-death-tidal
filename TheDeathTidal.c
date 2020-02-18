// TheDeathTidal.c

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "Sector.h"
#include "Area.h"
#include "Item.h"
#include "Storage.h"
#include "Character.h"
#include "Car.h"
#include "constantes.h"
#include "Initialisation.h"
#include "TheDeathTidal.h"

int main() {
	int contamination;
	Area *currentArea;
	Sector *currentSector;
	Character *player;
	Car **cars;
	Sector **carsLocation;
	
	Area *area0 = createArea0();
	
	contamination = 0;
	currentArea = area0;
	currentSector = currentArea->sectors[0];
	player = createPlayer("Rambo");
	cars = createCars();
	carsLocation = createCarsLocation(NB_CARS, area0->sectors[1]);
	
	while (isAlive(player)) {
		int entry = -1;
		printf("\n");
		printf("CONTAMINATION : %d\n", contamination);
		printf("Secteur : "); displayName(currentSector); printf("\n");
		if (isACarHere(currentSector, carsLocation)) {
			printf("Voiture : "); displayCars(currentSector, carsLocation, cars); printf("\n");
		}
		
		printf("\n");
		printf("ACTIONS\n");
		// Déplacement
		printf("\t1 SE DEPLACER ("); displayNeighbors(currentSector); printf(")\n");
		
		// Choix
		do {
			scanf("%d", &entry);
			switch (entry) {
				case 1:
					displayMoveChoice(currentSector);
					moveChoice(&currentSector);
					break;
				case 2:
					printf("case 2\n");
					break;
				default:
					entry = -1;
			}
		} while(entry!=1);
	}
	
	return 0;
}

bool isACarHere(Sector *sector, Sector **carsLocation) {
	for (int i=0; i<NB_CARS; i++)
		if (carsLocation[i] == sector)
			return true;
	return false;
}

void displayCars(Sector *sector, Sector **carsLocation, Car **cars) {
	bool atLeastOneCar = false;
	for (int i=0; i<NB_CARS; i++) {
		if (carsLocation[i] == sector) {
			if (atLeastOneCar) {
				atLeastOneCar = false;
				printf(", ");
			}
			printf("%s", cars[i]->name);
		}
	}
}

void displayMoveChoice(Sector *from) {
	Sector *to;
	printf("\n");
	printf("CHOIX DU LIEU\n");
	for (int i=0; i<from->neighbors_nb; i++) {
		to = from->neighbors[i];
		printf("\t%d ", i+1); displayName(to); printf(" ("); displayMoveCost(from, to); printf(")\n");
	}
	printf("\t0 QUITTER\n");
}

void displayMoveCost(Sector *from, Sector *to) {
	int costHungerTotal = 0;
	int costThirstTotal = 0;
	char* unknownSign = "";
	
	if (from->revealed) {
		costHungerTotal += costHunger(from);
		costThirstTotal += costThirst(from);
	}
	if (to->revealed) {
		costHungerTotal += costHunger(to);
		costThirstTotal += costThirst(to);
	}
	if (!to->revealed)
		unknownSign = "+";
	printf("Hunger : %d%s, Thirst : %d%s", costHungerTotal, unknownSign, costThirstTotal, unknownSign);
}

void moveChoice(Sector **sector) {
	int entry;
	bool moved = false;
	Sector *from = *sector;
	do {
		entry = -1;
		scanf("%d", &entry);
		if ( entry > 0 && entry <= from->neighbors_nb) {
			move(sector, from->neighbors[entry-1]);
			moved = true;
		}
	} while( entry != 0 && !moved );
}

void move(Sector **currentSector, Sector *newSector) {
	*currentSector = newSector;
}