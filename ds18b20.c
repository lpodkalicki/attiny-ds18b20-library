/**
 * Copyright (c) 2018, Łukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 *
 * This is tinyAVR (ATtiny13, ATtiny25, ATtiny45, ATtiny85) library for DS18B20 temperature sensor.
 */

#include "onewire.h"
#include "ds18b20.h"

void
DS18B20_init(uint8_t pin)
{

	onewire_init(pin);
}

int16_t
DS18B20_read(void)
{
	uint8_t msb, lsb;
	int8_t sign = 1;
	uint16_t t;

	onewire_reset();
	onewire_write(ONEWIRE_SKIP_ROM);
	onewire_write(DS18B20_CONVERT_T);

	onewire_reset();
	onewire_write(ONEWIRE_SKIP_ROM);
	onewire_write(DS18B20_READ);

	lsb = onewire_read();
	msb = onewire_read();
	t = ((uint16_t)msb << 8) | lsb;

	if ((msb & 0xf8) == 0xf8) {		
		t = (65536 - t);
		sign = -1;
	}

	return sign * (((uint16_t)t * 10U) / 16U);
}
