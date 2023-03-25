#include <iostream>
#include <Pet.h>

enum MOODS
{
    HAPPY,
    SAD,
    // ...
};

// NOTE(MSR): This might go in h file.
struct Pet
{
    // Add the variables that constitute our pet
    Personality p;
};

typedef struct Personality
{
    MOODS mood;
    int occ; // occurance
};



int main()
{

    Pet dog;

    dog.p.mood = HAPPY;
    dog.p.occ = 50;

    

    return 0;
}