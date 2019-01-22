/*

Use mikroE Timer Calculator to generate proper timer configuration
and timer ISR.

https://www.mikroe.com/timer-calculator

*/
#include "Click_GPS4_types.h"

uint32_t timerCounter = 0;
static void gps4_configTimer();

static void gps4_configTimer()
{
    TIMER32_T32CONTROL1 &= 0xFFFFFFFE;
    TIMER32_T32CONTROL1 |= 0x02;
    TIMER32_T32CONTROL1 |= 0;
    TIMER32_T32CONTROL1 |= 0x20;
    TIMER32_T32CONTROL1 |= 0x40;
    TIMER32_T32LOAD1 = 0x0000BB80;
    NVIC_IntEnable(IVT_INT_T32_INT1);
    TIMER32_T32CONTROL1 |= 0x80;
    EnableInterrupts();
}

void Timer_interrupt() iv IVT_INT_T32_INT1
{
    gps4_tick();
	timerCounter++;
    TIMER32_T32INTCLR1 = 1;
}
