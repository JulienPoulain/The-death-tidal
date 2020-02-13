// Car.h

#ifndef CAR_H
#define CAR_H

typedef struct Car Car;
struct Car {
	char *name;
	int health;
	int fuelReserve;
	Storage trunk;
};

#endif