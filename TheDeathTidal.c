// TheDeathTidal.c

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "Sector.h"
#include "Area.h"
#include "TheDeathTidal.h"

#define NB_AREA 3
#define NB_SECTOR_AREA_0 3
#define NB_SECTOR_AREA_1 3
#define NB_SECTOR_AREA_2 3

int main() {
	int contamination;
	Area currentArea;
	Sector *currentSector;
	
	Area *area0 = createArea0();
	
	contamination = 0;
	currentArea = *area0;
	currentSector = area0->sectors[0];
	
	printf("Contamination : %d\n", contamination);
	printf("Zone : %s\n", currentArea.name);
	printf("Secteur : %s\n", currentSector->name);
	printf("Prochain secteur : %s\n", currentSector->neighbors[0]->name);
	
	return 0;
}