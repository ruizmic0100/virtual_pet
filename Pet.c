#include <stdio.h>
#include "Pet.h"

Pet makeHappy(Pet pet){
    pet.mood = happy;
    return pet;
}
Pet makeSad(Pet pet){
    pet.mood = sad;
    return pet;
}
Pet makeNeutral(Pet pet){
    pet.mood = neutral;
    return pet;
}
Pet sleep(Pet pet){
    pet.stamina = 100;
    return pet;
}
Pet feed(Pet pet){
    pet.hunger += 25;
    if(pet.hunger > 100){
        pet.hunger = 100;
    }


    // code
    return pet;
}
Pet walk(Pet pet){
    pet.stamina -= 25;
    if(pet.stamina < 0){
        pet.stamina = 0;
    }
    return pet;
}

int main()
{

    return 0;
}