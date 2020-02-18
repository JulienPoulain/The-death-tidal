// Car.h

#ifndef CAR_H
#define CAR_H

typedef struct Storage Storage;
typedef struct Sector Sector;

typedef struct Car Car;
struct Car {
	char *name;
	int health;
	int health_max;
	int fuel;
	int fuel_max;
	Storage *trunk;
};

#endif