/*
	Timer class
	
	DEPENDENCIES:
	An interrupt handling system has to be set up (it is already). This class only manages the timer registers.
	
	EXAMPLE INTERRUPT HANDLING SYSTEM:
	See tm4c123gh6pm_startup_ccs.c file for NVIC vector table. (-> Entry for Timer0IntHandler)
 */

#ifndef TIMER_H_
#define TIMER_H_
#define RCGCTIMER_Base 0x400FE000
#define RCGCTIMER_offset 0x604
#define GPTMCTL_Base 0x40030000
#define GPTMCTL_offset 0x00C
#define GPTMCFG_Base 0x40030000
#define GPTMCFG_offset 0x000
#define GPTMTAMR_Base 0x40030000
#define GPTMTAMR_offset 0x004
#define GPTMTAILR_Base 0x40030000
#define GPTMTAILR_offset 0x028
#define GPTMIMR_Base 0x40030000
#define GPTMIMR_offset 0x018
#define EN0 0xE000E100
class Timer {
private:
	void cleanUp( void );
	
public:
	Timer();
	~Timer();
	static void resetInterruptFlag( void );
	bool initTimer( unsigned long frequency );
	void enableTimerBlockClock(void);
	void setIsTimerEnabled( bool enabled );
	void setIsTimerInterruptEnabled( bool enabled );
};

#endif /* TIMER_H_ */


