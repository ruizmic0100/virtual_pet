#ifndef PET_H
#define PET_H

#include "anim.h"

typedef enum MOODS {sad,neutral,happy} moods;

typedef struct Pet
{
    // Add the variables that constitute our pet
    moods mood;
    int hunger;
    int stamina;
    char name[15];
}Pet;

// Function prototypesss
Pet* initPet();
void makeHappy(Pet* pet);
void makeSad(Pet* pet);
void makeNeutral(Pet* pet);
void sleep(Pet* pet);
void feed(Pet* pet);
void walk(Pet* pet);


#endif