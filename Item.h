// Item.h

#ifndef ITEM_H
#define ITEM_H

typedef enum ItemType Itemtype;
enum ItemType {DRINK, FOOD, FUEL, AMMUNITION};

typedef struct Item Item;
struct Item {
	char *name;
	ItemType type;
	int value;
	int weight_unitary;
	int weight_total;
	int quantity_max;
	int quantity_current;
};

#endif