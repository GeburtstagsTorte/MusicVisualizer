/*
 *  Use this class for the implementation of the GPIO (digital) Sensor - Object
*/
#ifndef GPIOSENSOR_H_
#define GPIOSENSOR_H_
#define RCGCGPIO_Base 0x400FE000
#define RCGCGPIO_offset 0x608
#define GPIODIR_offset 0x400
#define GPIODIR_Base 0x40004000
#define GPIODATA_offset 0x000
#define GPIODR2R_Base 0x40004000
#define GPIODR2R_offset 0x500
#define GPIOAFSEL_Base 0x40004000
#define GPIOAFSEL_offset 0x420
#define GPIOPUR_Base 0x40004000
#define GPIOPUR_offset 0x510
#define GPIODEN_Base 0x40004000
#define GPIODEN_offset 0x51C
#define GPIOAMSEL_Base 0x40004000
#define GPIOAMSEL_offset 0x528


#include "../Configuration/Configuration.h"
#include "../bitmacros.h"


class GPIOSensor {
	
private:

public:
	GPIOSensor();
	~GPIOSensor();

	void init( Configuration::s_GPIOSensorConfig* thisGPIOSensorConfig_ );
	bool getValue();
	void cleanUp();
};

#endif /* GPIOSENSOR_H_ */

