/*****************************************************************************
* | File      	:   LCD_1in8_test.c
* | Author      :   Waveshare team
* | Function    :   1.8inch LCD test demo
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2021-08-20
* | Info        :
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
// RESOLUTION 160x128
#include "LCD_Test.h"
#include "LCD_1in8.h"
#include "Pet.h"

void animationTest(UDOUBLE ImageSize, UWORD* BlackImage);
Pet dogInit();


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

    // Create Pet: Dog
    Pet dog = dogInit();

    
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
    
    // /* GUI */
    printf("drawing...\r\n");
    // /*2.Drawing on the image*/

   	// Paint_DrawPoint(2,1, BLACK, DOT_PIXEL_1X1,  DOT_FILL_RIGHTUP);//240 240

	// Paint_DrawLine( 10,  5, 40, 35, MAGENTA, DOT_PIXEL_2X2, LINE_STYLE_SOLID);

    // Paint_DrawLine( 80,  20, 110, 20, CYAN, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);

    // Paint_DrawRectangle(10, 5, 40, 35, RED, DOT_PIXEL_2X2,DRAW_FILL_EMPTY);

    // Paint_DrawCircle(95, 20, 15, GREEN, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    
    // Print out pet's name:
    char buf[30];
    sprintf(buf, "%s", dog.name);
    Paint_DrawString_EN (1,96 , buf, &Font12, WHITE,  BLACK);

    // /*3.Refresh the picture in RAM to LCD*/
  	LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(1000);
    Paint_Clear(WHITE);
  	LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(10);
    LCD_1IN8_Clear(WHITE);

    Paint_DrawImage(gBlue_WeirdThing,0,1,32,32);
    LCD_1IN8_Display(BlackImage);
    DEV_Delay_ms(1000);

    while (1)
        // animationTest(Imagesize, BlackImage);

    // Paint_DrawImage(gImage_1inch8_1,0,1,160,128);
    // LCD_1IN8_Display(BlackImage);
    // DEV_Delay_ms(2000);
     

    /* Module Exit */
    free(BlackImage);
    BlackImage = NULL;
    
    
    DEV_Module_Exit();
    return 0;
}

void animationTest(UDOUBLE ImageSize, UWORD* BlackImage)
{
    for (int x=0; x < 50; x++) {
        Paint_DrawPoint(2,x, BLACK, DOT_PIXEL_1X1,  DOT_FILL_RIGHTUP);//240 240
        LCD_1IN8_Display(BlackImage);
        DEV_Delay_ms(30);
        Paint_Clear(WHITE);
    }
}

Pet dogInit()
{
    Pet tempPet;

    strcpy(tempPet.name, "Doggie");
    tempPet.stamina = 100;
    tempPet.hunger = 100;

    return tempPet;
}
