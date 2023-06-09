#include <stdio.h>
#include "anim.h"

#define ANIMATION_SPEED 100

void dogEatingAnim(UWORD* BlackImage) {

    Paint_DrawImage(pug_eating_001,0,1,128,128);
    LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(ANIMATION_SPEED);
    Paint_Clear(WHITE);
    Paint_DrawImage(pug_eating_002,0,1,128,128);
    LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(ANIMATION_SPEED);
    Paint_Clear(WHITE);
}

void dogSleepingAnim(UWORD* BlackImage) {

    Paint_DrawImage(pug_sleeping_001,8,10,126,121);
    LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(ANIMATION_SPEED);
    Paint_Clear(WHITE);

    Paint_DrawImage(pug_sleeping_002,8,10,126,121);
    LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(ANIMATION_SPEED);
    Paint_Clear(WHITE);

    Paint_DrawImage(pug_sleeping_003,8,10,126,121);
    LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(ANIMATION_SPEED);
    Paint_Clear(WHITE);
}

void dogWalkingAnim(UWORD* BlackImage) {

    Paint_DrawImage(pug_rs_004,0,1,128,128);
    LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(ANIMATION_SPEED);
    Paint_Clear(WHITE);

    Paint_DrawImage(pug_rs_005,0,1,128,128);
    LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(ANIMATION_SPEED);
    Paint_Clear(WHITE);

    Paint_DrawImage(pug_rs_006,0,1,128,128);
    LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(ANIMATION_SPEED);
    Paint_Clear(WHITE);
}

void dogHappyAnim(UWORD* BlackImage) {

    Paint_DrawImage(pug_jump_001,5,10,128,128);
    LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(ANIMATION_SPEED);
    Paint_Clear(WHITE);

    Paint_DrawImage(pug_jump_002,5,10,128,128);
    LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(ANIMATION_SPEED);
    Paint_Clear(WHITE);

    Paint_DrawImage(pug_jump_003,5,10,128,128);
    LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(ANIMATION_SPEED);
    Paint_Clear(WHITE);
}

void dogSadAnim(UWORD* BlackImage) {

    Paint_DrawImage(pug_sad_001,0,1,128,128);
    LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(ANIMATION_SPEED);
    Paint_Clear(WHITE);

    Paint_DrawImage(pug_sad_002,0,1,128,128);
    LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(ANIMATION_SPEED);
    Paint_Clear(WHITE);
}

void dogNeutralAnim(UWORD* BlackImage) {

    Paint_DrawImage(pug_rs_005,0,1,128,128);
    LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(ANIMATION_SPEED+500);
    Paint_Clear(WHITE);
}

void introAnim(UWORD* BlackImage) {

    for (int i=0;i<10;i++) {

        Paint_DrawImage(pug_rs_004,i,5,128,128);
        LCD_1IN8_Display(BlackImage);
        DEV_Delay_ms(ANIMATION_SPEED);
        Paint_Clear(WHITE);

        Paint_DrawImage(pug_rs_005,i,5,128,128);
        LCD_1IN8_Display(BlackImage);
        DEV_Delay_ms(ANIMATION_SPEED);
        Paint_Clear(WHITE);

        Paint_DrawImage(pug_rs_006,i,5,128,128);
        LCD_1IN8_Display(BlackImage);
        DEV_Delay_ms(ANIMATION_SPEED);
        Paint_Clear(WHITE);
    }

    dogHappyAnim(BlackImage);
    dogNeutralAnim(BlackImage);
    Paint_DrawString_EN(60,60, "PocketPals!", &Font12, BLACK, WHITE);
    LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(2000);
}

void poopAnim(UWORD* BlackImage) {

    Paint_DrawImage(pug_ls_010,50,20,128,128);
    LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(ANIMATION_SPEED);
    // Paint_Clear(WHITE);
    //HOW CAN I MAKE THE POOP AND THE LS10 PRINT SME TME (NO CLEAR)
    Paint_DrawImage(pug_poop_001,20,100,128,128);
    LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(ANIMATION_SPEED);
    Paint_Clear(WHITE);
}