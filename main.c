#define AUTO_COUNT 0
/*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
 */

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
 */
#include "mcc_generated_files/system/system.h"

#define COMMON PORTAbits.RA5

#define D4AB PORTAbits.RA4

#define D3A PORTCbits.RC5
#define D3B PORTCbits.RC4
#define D3C PORTCbits.RC3
#define D3D PORTCbits.RC6
#define D3E PORTCbits.RC7
#define D3F PORTBbits.RB7
#define D3G PORTBbits.RB6

#define D2A PORTBbits.RB5
#define D2B PORTBbits.RB4
#define D2C PORTCbits.RC2
#define D2D PORTCbits.RC1
#define D2E PORTCbits.RC0
#define D2F PORTAbits.RA2
#define D2G PORTAbits.RA1

void Display(int a);
/*
    Main application
 */

char toggle = 0;
char counter = 0;
char RA0Value = 1;

struct digit {
    char a;
    char b;
    char c;
    char d;
    char e;
    char f;
    char g;
} typedef Digit;


Digit one;
Digit ten;
Digit hundred;

void ClearDigit(Digit* digit) {
    digit->a = 0;
    digit->b = 0;
    digit->c = 0;
    digit->d = 0;
    digit->e = 0;
    digit->f = 0;
    digit->g = 0;
}

void Tmr1CallBack(void) {
    toggle = 1 - toggle;

    COMMON = toggle;

    D4AB = toggle ^ !hundred.a &
            hundred.b &
            hundred.c &
            !hundred.d &
            !hundred.e &
            !hundred.f &
            !hundred.g;


    D3A = toggle ^ ten.a;
    D3B = toggle ^ ten.b;
    D3C = toggle ^ ten.c;
    D3D = toggle ^ ten.d;
    D3E = toggle ^ ten.e;
    D3F = toggle ^ ten.f;
    D3G = toggle ^ ten.g;

    D2A = toggle ^ one.a;
    D2B = toggle ^ one.b;
    D2C = toggle ^ one.c;
    D2D = toggle ^ one.d;
    D2E = toggle ^ one.e;
    D2F = toggle ^ one.f;
    D2G = toggle ^ one.g;
    
    if (RA0Value)
    {
        RA0Value = 0;
        Display(++counter);
    }
}

void SetSegments(Digit* digit, int a, char blank) {
    if (blank) {
        digit->a = 0;
        digit->b = 0;
        digit->c = 0;
        digit->d = 0;
        digit->e = 0;
        digit->f = 0;
        digit->g = 0;
    } else {
        switch (a) {
            case 0:
                digit->a = 1;
                digit->b = 1;
                digit->c = 1;
                digit->d = 1;
                digit->e = 1;
                digit->f = 1;
                digit->g = 0;
                break;

            case 1:
                digit->a = 0;
                digit->b = 1;
                digit->c = 1;
                digit->d = 0;
                digit->e = 0;
                digit->f = 0;
                digit->g = 0;
                break;

            case 2:
                digit->a = 1;
                digit->b = 1;
                digit->c = 0;
                digit->d = 1;
                digit->e = 1;
                digit->f = 0;
                digit->g = 1;
                break;

            case 3:
                digit->a = 1;
                digit->b = 1;
                digit->c = 1;
                digit->d = 1;
                digit->e = 0;
                digit->f = 0;
                digit->g = 1;
                break;

            case 4:
                digit->a = 0;
                digit->b = 1;
                digit->c = 1;
                digit->d = 0;
                digit->e = 0;
                digit->f = 1;
                digit->g = 1;
                break;

            case 5:
                digit->a = 1;
                digit->b = 0;
                digit->c = 1;
                digit->d = 1;
                digit->e = 0;
                digit->f = 1;
                digit->g = 1;
                break;

            case 6:
                digit->a = 1;
                digit->b = 0;
                digit->c = 1;
                digit->d = 1;
                digit->e = 1;
                digit->f = 1;
                digit->g = 1;
                break;

            case 7:
                digit->a = 1;
                digit->b = 1;
                digit->c = 1;
                digit->d = 0;
                digit->e = 0;
                digit->f = 0;
                digit->g = 0;
                break;

            case 8:
                digit->a = 1;
                digit->b = 1;
                digit->c = 1;
                digit->d = 1;
                digit->e = 1;
                digit->f = 1;
                digit->g = 1;
                break;

            case 9:
                digit->a = 1;
                digit->b = 1;
                digit->c = 1;
                digit->d = 1;
                digit->e = 0;
                digit->f = 1;
                digit->g = 1;
                break;
        }
    }
}

void Display(int a) {
    int ones = a % 10;
    int tens = (a / 10) % 10;
    int hundreds = a > 99;

    SetSegments(&one, ones, 0);
    SetSegments(&ten, tens, (a < 10));
    SetSegments(&hundred, hundreds, 0);
}

int main(void) {
    SYSTEM_Initialize();

    COMMON = 1;

    ClearDigit(&one);
    ClearDigit(&ten);
    ClearDigit(&hundred);

    one.b = 1;
    one.c = 1;

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    TMR1_OverflowCallbackRegister(Tmr1CallBack);
    
    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 

#if AUTO_COUNT
    int i = 0;

    while (1) {
        Display(i++);

        if (i > 199) {
            i = 0;
        }
        __delay_ms(100);
    }
#else
    Display(counter);

    while (1)
    {
        if (!RA0)
        {
          RA0Value = 1;
          while (!RA0)
          {              
              __delay_ms(30);
          }
        }
    }
#endif    
}