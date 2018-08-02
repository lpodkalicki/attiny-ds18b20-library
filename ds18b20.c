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

uint16_t
DS18B20_read(void)
{
	uint16_t t;

	onewire_reset();
	onewire_write(ONEWIRE_SKIP_ROM);
	onewire_write(DS18B20_CONVERT_T);

	onewire_reset();
	onewire_write(ONEWIRE_SKIP_ROM);
	onewire_write(DS18B20_READ);

      	t = onewire_read();
      	t |= (uint16_t)onewire_read() << 8;

	return ((t >> 4) * 100 + ((t << 12) / 6553) * 10);
}
