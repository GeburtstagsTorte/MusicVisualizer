#include "GPIOSensor.h"
#include<stdio.h>
GPIOSensor::GPIOSensor() {

}

GPIOSensor::~GPIOSensor() {
}

void GPIOSensor::init( Configuration::s_GPIOSensorConfig* thisGPIOSensorConfig_ ){
    HWACC(RCGCGPIO_Base + RCGCGPIO_offset) |=0x1;                                         /*Aktivieren des GPIO Port A */
    HWACC(GPIODIR_Base + GPIODIR_offset) &=~(1<<2);                                       /*Defintion von Port A als Input*/
    HWACC(GPIOAFSEL_Base + GPIOAFSEL_offset)  &=~(1<<2);                                  /*Defintion von Pin 2 als GPIO*/
    HWACC(GPIODR2R_Base + GPIODR2R_offset) |=0x4;                                         /*Antrieb mit 2mA*/
    HWACC(GPIOPUR_Base + GPIOPUR_offset) |=0x4;                                           /*Aktivierung des Pull-up Wiederstandes */
    HWACC(GPIOAMSEL_Base + GPIOAMSEL_offset) &=~(1<<2);                                   /*Deaktivierung der Analog Funktion von Pin2*/
    HWACC(GPIODEN_Base + GPIODEN_offset) |=0x4;                                           /*Aktivierung der Digitalen Fuktion von Pin2*/
}
bool GPIOSensor::getValue() {                                                             /*Gibt den aktuellen Wert des Snsors zurück*/
    if (HWACC (GPIODIR_Base + ((1<<2)<<2)) == (0x1<<2)){
        return true;
       }
    else {
       return false;
         }
}
void GPIOSensor::cleanUp(){
    HWACC(GPIODIR_Base + GPIODATA_offset) &=0x00000000;                                    /*Deaktivert Ausgangspins und löscht Variablen*/
};


