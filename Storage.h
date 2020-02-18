// Storage.h

#ifndef STORAGE_H
#define STORAGE_H

typedef struct Item Item;

typedef struct Storage Storage;
struct Storage {
	char *name;
	Item *item;
	// Nombre d'objets différents pouvant être contenu.
	int size_max;
	int size_current;
	// Poids total pouvant être supporté par le contenant.
	int capacity_max;
	int capacity_current;
};

#endif