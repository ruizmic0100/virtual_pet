#ifndef ANIM_H
#define ANIM_H

#include "DEV_Config.h"
#include "../lib/GUI/GUI_Paint.h"
#include "pug_data.h"
#include "../../c/lib/LCD/LCD_1in8.h"

// prototype functions
void dogEatingAnim(UWORD* BlackImage);
void dogSleepingAnim(UWORD* BlackImage);
void dogWalkingAnim(UWORD* BlackImage);
void dogHappyAnim(UWORD* BlackImage);
void dogSadAnim(UWORD* BlackImage);
void dogNeutralAnim(UWORD* BlackImage);
void introAnim(UWORD* BlackImage);
void poopAnim(UWORD* BlackImage);
#endif // ANIM_H