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
    SYSCTL_RCGCTIMER_R0_bit = 1;
    TIMER_CTL_TAEN_bit = 0;
    TIMER0_CFG   = 4;
    TIMER0_TAMR |= 2;
    TIMER0_TAPR  = 1;
    TIMER0_TAILR = 60000;
    NVIC_IntEnable(IVT_INT_TIMER0A_16_32_bit);
    TIMER_IMR_TATOIM_bit = 1;
    TIMER_CTL_TAEN_bit   = 1;
    EnableInterrupts();
}

void Timer_interrupt() iv IVT_INT_TIMER0A_16_32_bit 
{
    gps4_tick();
	timerCounter++;
    TIMER_ICR_TATOCINT_bit = 1;
}
