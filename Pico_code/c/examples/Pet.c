#include <stdio.h>
#include "Pet.h"

Pet* initPet(){
    Pet* newpet;
    newpet = (Pet*)malloc(sizeof(Pet)+10);
    newpet->hunger=100;
    newpet->mood = happy;
    newpet->stamina = 100;
    strcpy(newpet->name,"Boba");

    return newpet;
}

void makeHappy(Pet* pet){
    pet->mood = happy;
}

void makeSad(Pet* pet){
    pet->mood = sad;
}

void makeNeutral(Pet* pet){
    pet->mood = neutral;
}

void sleep(Pet* pet){
    pet->stamina = 100;
}

void feed(Pet* pet){
    pet->hunger += 25;
    if(pet->hunger > 100){
        pet->hunger = 100;
    }
}

void walk(Pet* pet){
    pet->stamina -= 25;
    if(pet->stamina < 0){
        pet->stamina = 0;
    }
}

void