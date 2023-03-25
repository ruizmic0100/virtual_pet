#ifndef PET_H
#define PET_H

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
Pet initPet();
Pet makeHappy(Pet pet);
Pet makeSad(Pet pet);
Pet makeNeutral(Pet pet);
Pet sleep(Pet pet);
Pet feed(Pet pet);
Pet walk(Pet pet);

// Any definitions needed globably.

#endif