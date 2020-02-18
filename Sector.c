// Sector.c

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "Sector.h"

void displayName(Sector *sector) {
	if (sector->revealed)
		printf("%s", sector->name);
	else
		printf("???");
}

void displayNeighbors(Sector *sector) {
	for (int i=0; i<sector->neighbors_nb; i++) {
		displayName(sector->neighbors[i]);
		if (i+1 < sector->neighbors_nb)
			printf(", ");
	}
}

int costHunger(Sector *sector) {
	SectorType sectorType = sector->sectorType;
	
	switch (sectorType) {
		case HOUSE:
		case ARMORY:
		case GAS_STATION:
			return 0;
			break;
		case PARKING:
		case ALLEY:
			return 1;
			break;
		case STREET:
		case BOULEVARD:
		case SHOPPING_MALL:
			return 2;
			break;
		case SUBWAY:
		case SEWER:
			return 3;
			break;
		default:
			return 0;
	};
}

int costThirst(Sector *sector) {
	SectorType sectorType = sector->sectorType;
	
	switch (sectorType) {
		case HOUSE:
		case ARMORY:
			return 0;
			break;
		case GAS_STATION:
		case SHOPPING_MALL:
			return 1;
			break;
		case ALLEY:
		case STREET:
		case BOULEVARD:
		case PARKING:
			return 2;
			break;
		case SUBWAY:
		case SEWER:
			return 3;
			break;
		default:
			return 0;
	};
}

bool isPassableByCar(Sector* sector) {
	SectorType sectorType = sector->sectorType;
	
	switch (sectorType) {
		case STREET:
		case BOULEVARD:
		case PARKING:
		case GAS_STATION:
			return true;
			break;
		case ALLEY:
		case SUBWAY:
		case SEWER:
		case HOUSE:
		case ARMORY:
		case SHOPPING_MALL:
			return false;
			break;
		default:
			return false;
	}
}