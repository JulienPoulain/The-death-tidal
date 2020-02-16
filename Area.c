// Area.c

#include <stdlib.h>
#include <stdbool.h>

#include "Sector.h"
#include "Area.h"

Area* createArea0() {
	Sector *s0 = malloc( sizeof(Sector) );
	Sector *s1 = malloc( sizeof(Sector) );
	Sector *s2 = malloc( sizeof(Sector) );
	Area *area = malloc( sizeof(Area) );
	
	s0->sectorType = HOUSE;
	s0->name = "Planque";
	s0->description = "Il vaut mieux ne pas traîner, cet endroit ne sera plus sûr très longtemps.";
	s0->entrance = true;
	s0->revealed = true;
	s0->neighbors_nb = 1;
	s0->neighbors = malloc( sizeof(Sector*) );
	
	s1->sectorType = STREET;
	s1->name = "Little street";
	s1->description = "La courte rue de cette petite ville, au bout il n'y a qu'une station service.";
	s1->entrance = false;
	s1->revealed = true;
	s1->neighbors_nb = 2;
	s1->neighbors = malloc( 2 * sizeof(Sector*) );

	s2->sectorType = GAS_STATION;
	s2->name = "Station service";
	s2->description = "La station service.";
	s2->entrance = true;
	s2->revealed = true;
	s2->neighbors_nb = 1;
	s2->neighbors = malloc( sizeof(Sector*) );
	
	s0->neighbors[0] = s1;
	s1->neighbors[0] = s0;
	s1->neighbors[1] = s2;
	s2->neighbors[0] = s1;
	
	area->name = "Starting town";
	area->description = "Jusqu'ici ce village isolé était épargné par les zombies. Mais les signes ne trompent pas, une maree va bientot s'abattre deferler. Il ne reste plus qu'a s'echapper le plus loin d'ici.";
	area->distance = 0;
	area->sectors = malloc( 3 * sizeof(Sector*) );
	
	area->sectors[0] = s0;
	area->sectors[1] = s1;
	area->sectors[2] = s2;
	
	return area;
}

/*void initArea0(Area *area) {
	Sector s0, s1, s2;
	
	s0 = (Sector) {
		.sectorType = HOUSE,
		.name = "Planque",
		.description = "Il vaut mieux ne pas traîner, cet endroit ne sera plus sûr très longtemps.",
		.entrance = true,
		.revealed = true,
		.neighbors_nb = 1,
		.neighbors = malloc( sizeof(Sector*) )
	};
	
	s1 = (Sector) {
		.sectorType = STREET,
		.name = "Little street",
		.description = "La courte rue de cette petite ville, au bout il n'y a qu'une station service.",
		.entrance = false,
		.revealed = true,
		.neighbors_nb = 2,
		.neighbors = malloc( 2 * sizeof(Sector*) )
	};
	
	s2 = (Sector) {
		.sectorType = GAS_STATION,
		.name = "Station service",
		.description = "La station service.",
		.entrance = true,
		.revealed = true,
		.neighbors_nb = 1,
		.neighbors = malloc( sizeof(Sector*) )
	};
	
	s0.neighbors[0] = &s1;
	s1.neighbors[0] = &s0;
	s1.neighbors[1] = &s2;
	s2.neighbors[0] = &s1;
	
	area->name = "Starting town";
	area->description = "Jusqu'ici ce village isolé était épargné par les zombies. Mais les signes ne trompent pas, une maree va bientot s'abattre deferler. Il ne reste plus qu'a s'echapper le plus loin d'ici.";
	area->distance = 0;
	area->sectors = malloc( 3 * sizeof(Sector*) );
	
	area->sectors[0] = &s0;
	area->sectors[1] = &s1;
	area->sectors[2] = &s2;
}*/