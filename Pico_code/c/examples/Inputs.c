#include "Inputs.h"

char getPlayerInputs()
{
    char playerInput = getchar_timeout_us(0);
    return playerInput;
}