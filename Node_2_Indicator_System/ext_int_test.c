 /* ext_int_test.c */                      // File name

#include <lpc21xx.h>                      // Header file for LPC21xx registers
#include "pin_function_defines.h"         // Header for pin function macros
#include "defines.h"                      // Header for user-defined macros

#define LEDS (0xFF<<8)                    // LEDs are connected from P0.8 to P0.15

// Function prototype for delay
void delay_ms(unsigned dlyMS);

// Interrupt Service Routine (ISR) declarations
void eint0_isr(void) __irq;
void eint1_isr(void) __irq;

// Function declarations to enable external interrupts
void Enable_EINT0(void);
void Enable_EINT1(void);

// Global variables
int l = 0, r = 0;                         // Flags for EINT0 and EINT1

//------------------------- MAIN FUNCTION -----------------------------

int main()
{
    Enable_EINT0();                       // Configure and enable External Interrupt 0
    Enable_EINT1();                       // Configure and enable External Interrupt 1

    while(1)                              // Infinite loop
    {
        // If left flag is ON and right flag is OFF
        if(l == 1 && r == 0)
        {
            int i;

            // Glow LEDs from right to left
            for(i = 15; i >= 8; i--)
            {
                IOCLR0 = (1<<i);          // Turn ON LED (Active LOW)
                delay_ms(120);            // Delay
                IOSET0 = (1<<i);          // Turn OFF LED
            }
        }

        // If right flag is ON and left flag is OFF
        if(l == 0 && r == 1)
        {
            int i;

            // Glow LEDs from left to right
            for(i = 8; i <= 15; i++)
            {
                IOCLR0 = (1<<i);          // Turn ON LED
                delay_ms(120);            // Delay
                IOSET0 = (1<<i);          // Turn OFF LED
            }
        }
    }
}

//----------------------- DELAY FUNCTION -----------------------------

void delay_ms(unsigned dlyMS)
{
    dlyMS *= 12000;                       // Convert milliseconds into loop count

    while(dlyMS--);                       // Wait until count becomes zero
}

//----------------------- EINT0 ISR ----------------------------------

void eint0_isr(void) __irq
{
    l = !l;                               // Toggle left flag (0?1 or 1?0)

    // CPLBIT(IOPIN0,EINT0_LED);          // Toggle ISR activity LED (optional)

    SSETBIT(EXTINT,0);                    // Clear EINT0 interrupt flag

    VICVectAddr = 0;                      // Inform VIC that ISR execution is complete

    WRITEBYTE(IOPIN0,8,0xFF);             // Turn OFF all LEDs

    delay_ms(100);                        // Small debounce delay
}

//----------------------- EINT1 ISR ----------------------------------

void eint1_isr(void) __irq
{
    r = !r;                               // Toggle right flag

    // CPLBIT(IOPIN0,EINT1_LED);          // Toggle ISR activity LED (optional)

    SSETBIT(EXTINT,1);                    // Clear EINT1 interrupt flag

    VICVectAddr = 0;                      // Clear interrupt in VIC

    WRITEBYTE(IOPIN0,8,0xFF);             // Turn OFF all LEDs

    delay_ms(100);                        // Debounce delay
}

//---------------------- ENABLE EINT0 -------------------------------

void Enable_EINT0(void)
{
    CFGPIN(PINSEL0,1,FUNC4);              // Configure P0.1 as EINT0

    // SETBIT(IODIR0,EINT0_LED);          // Optional ISR LED pin as output

    WRITEBYTE(IODIR0,8,0xFF);             // Configure P0.8-P0.15 as output

    WRITEBYTE(IOPIN0,8,0xFF);             // Turn OFF all LEDs initially

    SSETBIT(VICIntEnable,14);             // Enable EINT0 interrupt in VIC

    VICVectCntl0 = 0x20 | 14;             // Enable vector slot 0 for interrupt 14

    VICVectAddr0 = (unsigned)eint0_isr;   // Load ISR address into vector slot

    SCLRBIT(EXTINT,0);                    // Clear pending EINT0 interrupt

    SETBIT(EXTMODE,0);                    // Configure EINT0 as Edge Triggered

    SETBIT(EXTPOLAR,0);                   // Falling edge trigger
}

//---------------------- ENABLE EINT1 -------------------------------

void Enable_EINT1(void)
{
    CFGPIN(PINSEL0,3,FUNC4);              // Configure P0.3 as EINT1

    // SETBIT(IODIR0,EINT1_LED);          // Optional ISR LED pin as output

    WRITEBYTE(IODIR0,8,0xFF);             // Configure LEDs as output

    WRITEBYTE(IOPIN0,8,0xFF);             // Turn OFF all LEDs

    SSETBIT(VICIntEnable,15);             // Enable EINT1 interrupt

    VICVectCntl1 = 0x20 | 15;             // Assign vector slot 1 to interrupt 15

    VICVectAddr1 = (unsigned)eint1_isr;   // Store ISR address

    SCLRBIT(EXTINT,1);                    // Clear pending EINT1 interrupt

    SETBIT(EXTMODE,1);                    // Configure EINT1 as Edge Triggered

    SETBIT(EXTPOLAR,1);                   // Rising edge trigger
}