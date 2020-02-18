// TheDeathTidal.h

#ifndef THE_DEATH_TIDAL_H
#define THE_DEATH_TIDAL_H

bool isACarHere(Sector*, Sector**);
void displayCars(Sector*, Sector**, Car**);
void displayMoveChoice(Sector*);
void displayMoveCost(Sector*, Sector*);
void moveChoice(Sector**);
void move(Sector**, Sector*);

#endif