// Sector.h

#ifndef SECTOR_H
#define SECTOR_H

typedef enum SectorType SectorType;
enum SectorType {
	// Voies d'accès
	ALLEY, STREET, BOULEVARD, SUBWAY, SEWER,
	// Bâtiments
	HOUSE, PARKING, ARMORY, GAS_STATION, SHOPPING_MALL
};

typedef struct Sector Sector;
struct Sector {
	SectorType sectorType;
	char *name;
	char *description;
	bool entrance;
	bool revealed;
	int neighbors_nb;
	Sector **neighbors;
};

void displayName(Sector*);
void displayNeighbors(Sector*);
int costHunger(Sector*);
int costThirst(Sector*);
bool isPassableByCar(Sector*);

#endif