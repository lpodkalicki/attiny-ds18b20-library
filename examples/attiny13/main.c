/**
 * Copyright (c) 2018, Łukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 *
 * This is ATtiny13 "Print Temperature" example using attiny-ds18b20-library.
 * https://github.com/lpodkalicki/attiny-ds18b20-library
 */

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "ds18b20.h"

#define	DS18B20_PIN	PB0

int
main(void)
{
	int16_t t;

	/* setup */
	DS18B20_init(DS18B20_PIN);

	/* loop */
	while (1) {
		t = DS18B20_read();
		uart_putt(t);
		_delay_ms(1000);
	}
}

