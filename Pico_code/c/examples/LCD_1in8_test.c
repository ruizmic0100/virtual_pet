#include "LCD_Test.h"
#include "LCD_1in8.h"

uint32_t get_time(void) {
    uint32_t internal_time = time_us_32();
    return internal_time;
}

bool reserved_addr(uint8_t addr) {
return (addr & 0x78) == 0 || (addr & 0x78) == 0x78;
}

int LCD_1in8_test(void)
{
    DEV_Delay_ms(100);
    printf("LCD_1in8_test Demo\r\n");
    if(DEV_Module_Init()!=0){
        return -1;
    }
    
    /* LCD Init */
    printf("1.8inch LCD demo...\r\n");
    LCD_1IN8_Init(HORIZONTAL);
    LCD_1IN8_Clear(WHITE);
    
    //LCD_SetBacklight(1023);
    UDOUBLE Imagesize = LCD_1IN8_HEIGHT*LCD_1IN8_WIDTH*2;
    UWORD *BlackImage;
    if((BlackImage = (UWORD *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        exit(0);
    }
    // /*1.Create a new image cache named IMAGE_RGB and fill it with white*/
    Paint_NewImage((UBYTE *)BlackImage,LCD_1IN8.WIDTH,LCD_1IN8.HEIGHT, 0, WHITE);
    Paint_SetScale(65);
    Paint_Clear(WHITE);
    Paint_SetRotate(ROTATE_0);
    Paint_Clear(WHITE);

    Pet* pug = initPet();

    uint32_t time = get_time();

    introAnim(BlackImage);

    // Main forever update loop
    while (1) {
        time = get_time();
        time /= 1000000;
        dogNeutralAnim(BlackImage);
        //makeNeutral(&pug);
        if(pug->mood == happy){
            dogHappyAnim(BlackImage);
        }
        if(pug->mood == sad){
            dogSadAnim(BlackImage);
        }
        if(pug->mood == neutral){
            dogNeutralAnim(BlackImage);
        }
        if(pug->stamina < 15){
            makeSad(pug);
            dogSleepingAnim(BlackImage);
            sleep(&pug);
        }
        if(time > 30 && pug->stamina > 50){
            makeNeutral(pug);
            dogSleepingAnim(BlackImage);
            sleep(&pug);
        }
        if(pug->hunger > 80 && pug->stamina > 50){
            makeHappy(&pug);
        }
        if(pug->hunger < 50 && pug->stamina < 50){
            makeSad(&pug);
        }
    }

    /* Module Exit */
    free(BlackImage);
    BlackImage = NULL;
    
    
    DEV_Module_Exit();
    return 0;
}