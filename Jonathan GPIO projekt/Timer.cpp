#include "Timer.h"
#include "../Configuration/Configuration.h"
#include "../bitmacros.h"

Timer::Timer() {
};

Timer::~Timer() {
	Timer::cleanUp();
}

void Timer::cleanUp( void ){
}

bool Timer::initTimer( unsigned long frequency ) {
    enableTimerBlockClock();
    HWACC(GPTMCTL_Base + GPTMCTL_offset) &= ~(0x1);                      /*Reset des Timers*/
    HWACC(GPTMCFG_Base + GPTMCFG_offset) = 0x00000000;                   /*Resetten des General Purpose Timer Register*/
    HWACC(GPTMTAMR_Base + GPTMTAMR_offset) = 0x222;                      /*Konfiguration in Periodic Mode*/
    HWACC(GPTMTAILR_Base + GPTMTAILR_offset) = 0x7A11F;                  /*Startwert des Zählregisters*/
    setIsTimerEnabled(true);                                             /*Aktivierung des Timers*/
    return true;
   }
void Timer::setIsTimerEnabled( bool enabled ) {
    if(enabled == true) {
        HWACC(EN0) |= 0x80000;                                            /*Aktiviert Interrupts*/
        HWACC(GPTMCTL_Base + GPTMCTL_offset) |= 0x1;                      /*Startet den Timer*/
    }
    else if (enabled == false){
        HWACC(EN0) &= ~(0x80000);                                         /*Deaktiviert Interrupts*/
        HWACC(GPTMCTL_Base + GPTMCTL_offset) &= ~(0x1);                   /*Stoppt den Timer*/
    }
}

void Timer::enableTimerBlockClock(){
    HWACC(RCGCTIMER_Base + RCGCTIMER_offset) |= 0x1;                       /*Aktivierung der Clock*/
}

void Timer::setIsTimerInterruptEnabled( bool enable ) {                    /*Aktivierung oder Deaktivierung der Interrupts*/
 if(enable == true){
     HWACC(GPTMIMR_Base + GPTMIMR_offset) |= 0x1;                          /*Setzen des Bits zur Aktivierung des Interrupsts*/
}
 else if(enable == false) {
     HWACC(GPTMIMR_Base + GPTMIMR_offset) &= ~(0x1);                       /*Setzen des Bits zur Deaktivierung des Interrupsts*/
      }
}

void Timer::resetInterruptFlag() {                                         /*Löscht Interrupt  Flag */
    HWACC(0x40030000  +  0x24) |= 0x1;
}

