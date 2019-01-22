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
    SIM_SCGC6 |= (1 << PIT);
    NVIC_IntEnable(IVT_INT_PIT0);
    PIT_MCR = 0x00;
    PIT_LDVAL0 = 119999;
    PIT_TCTRL0 |= 2;
    PIT_TCTRL0 |= 1;
    EnableInterrupts();
}

void Timer_interrupt() iv IVT_INT_PIT0
{
    gps4_tick();
	timerCounter++;
    PIT_TFLG0.TIF = 1;
}
