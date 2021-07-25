/**
 * Copyright (c) 2018, Łukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 *
 * This is tinyAVR (ATtiny13, ATtiny25, ATtiny45, ATtiny85) library for DS18B20 temperature sensor.
 */

#ifndef _ATTINY_DS18B20_H_
#define _ATTINY_DS18B20_H_

#include <stdint.h>

#define	DS18B20_CONVERT_T	0x44
#define	DS18B20_READ		0xBE

/* Read temperature (Celcius).
 * Returns real number rounded to two decimal places as integer.
 * For example, to get decimal value:
 *  temp = DS18B20_read() / 100;
 */
int16_t DS18B20_read(uint8_t pin);

#endif	/* !_ATTINY_DS18B20_H_ */
