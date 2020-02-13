// Sector.h

#ifndef SECTOR_H
#define SECTOR_H

typedef struct Sector Sector;
struct Sector {
	char *name;
	char *description;
	bool revealed;
	Sector *neighbors;
};

#endif