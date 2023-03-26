#include "LCD_Test.h"
#include "LCD_1in8.h"

/* Global States */
int poopPresent;

/** This grabs the internal clock time used for timing.
 * 
 *  @return void
*/
uint32_t get_time(void) {
    uint32_t internal_time = time_us_32();
    return internal_time;
}

/** USB/UART Communication Init
 *
 * @return if it's own addr is valid.
*/
bool reserved_addr(uint8_t addr) {
return (addr & 0x78) == 0 || (addr & 0x78) == 0x78;
}

/** PocketPals Main Gameplay Loop
 * 
 * @returns Exits the program.
*/
int LCD_1in8_test(void)
{
    DEV_Delay_ms(100); // For board init purposes.

    uint32_t currTime = get_time(); // Get the time immediately once the program starts.

    if(DEV_Module_Init()!=0){
        return -1;
    }
    
    /* LCD Init */
    LCD_1IN8_Init(HORIZONTAL);
    LCD_1IN8_Clear(WHITE);
    UDOUBLE Imagesize = LCD_1IN8_HEIGHT*LCD_1IN8_WIDTH*2;
    UWORD *BlackImage;
    if((BlackImage = (UWORD *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        exit(0);
    }

    // Create a new blank image cache named BlackImage and fill it with white.
    Paint_NewImage((UBYTE *)BlackImage,LCD_1IN8.WIDTH,LCD_1IN8.HEIGHT, 0, WHITE);
    Paint_SetScale(65);
    Paint_Clear(WHITE);
    Paint_SetRotate(ROTATE_0);
    Paint_Clear(WHITE);


    /* ---- Main Gameplay Init's ---- */
    Pet* pug = initPet(); // Create our pet.
    poopPresent = 0; // NO POOP!

    introAnim(BlackImage); // Intro animation function.

    // Main Update Loop.
    // This also is where our state stack is implemented for the gameplay loop.
    while (1) {

        currTime = get_time(); // Update the time.
        currTime /= 1000000; // Convert to seconds.

        char playerInput = getPlayerInputs();

        switch(playerInput) {
            case 'f':
                printf("Feeding...\n");
                feed(pug);
                break;
            case 'w':
                printf("Walking...\n");
                walk(pug);
                break;
            case 'p':
                dogHappyAnim(BlackImage);
                printf("Petting...\n");
                break;
            case 'c':
                printf("Cleaning up poop...\n");
                if (poopPresent) {
                    poopPresent = 0;
                    Paint_Clear(WHITE);
                    dogHappyAnim(BlackImage);
                }
                break;
            default:
                printf("Wainting for player input...\n");
        }
        printf("Pug Stats: %i %i %i\t", pug->hunger, pug->stamina, pug->mood);

        // Check for mood.
        if(pug->mood == happy){
            dogHappyAnim(BlackImage);
        }
        if(pug->mood == sad){
            dogSadAnim(BlackImage);
        }
        if(pug->mood == neutral){
            dogNeutralAnim(BlackImage);
        }


        // Update anim based on pet stats.
        if(pug->stamina < 15){
            makeNeutral(pug);
            dogSleepingAnim(BlackImage);
            DEV_Delay_ms(3000);
            sleep(&pug); // Reset the pet's stamina.
        }
        if(currTime > 30 && pug->stamina < 50){
            makeNeutral(pug);
            dogSleepingAnim(BlackImage);
            sleep(&pug);
        }

        // if(pug->hunger > 80 && pug->stamina > 50){
        //     makeHappy(&pug);
        // }
        // if(pug->hunger < 25 && pug->stamina < 25 && (currTime%30) == 0){ 
        //     makeSad(&pug);
        //     dogSadAnim(BlackImage);
        // }

        if ((currTime%20) == 0) {
            poopAnim(BlackImage);
            poopPresent = 1;
            DEV_Delay_ms(2000);
        }

        // makeNeutral(&pug); // Set the default mood to be neutral when not happy or sad.
    }

    /* Module Exit */
    free(BlackImage);
    BlackImage = NULL;
    
    
    DEV_Module_Exit();
    return 0;
}