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


    // Configure Timer
}

void Timer_interrupt()
{
    gps4_tick();
	timerCounter++;
    // Reset Flag
}