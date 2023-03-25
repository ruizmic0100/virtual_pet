#ifndef PET_H
#define PET_H

enum MOODS {sad,neutral,happy};

typedef struct Pet
{
    // Add the variables that constitute our pet
    MOODS mood;
    int hunger;
    int stamina;
    char name[15];
}Pet;

// Function prototypesss
Pet makeHappy(Pet pet);
Pet makeSad(Pet pet);
Pet makeNeutral(Pet pet);
Pet sleep(Pet pet);
Pet feed(Pet pet);
Pet walk(Pet pet);

// Any definitions needed globably.

#endif