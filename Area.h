// Area.h

#ifndef AREA_H
#define AREA_H

typedef struct Area Area;
struct Area {
	char *name;
	char *description;
	int distance;
	Sector **sectors;
};

Area* createArea0();

#endif