# DS18B20 Library
This is tinyAVR (ATtiny13, ATtiny25, ATtiny45, ATtiny85, etc.) library for DS18B20 temperature sensor.

## Example Code
This example demonstrates how to use library and read temperature from DS18B20.

```c
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "ds18b20.h"

#define	DS18B20_PIN	PB0

int
main(void)
{
	uint16_t t;

	/* setup */	
	DS18B20_init(DS18B20_PIN);

	/* loop */
	while (1) {
		t = DS18B20_read();
		uart_putt(t);
		_delay_ms(1000);
	}
}

```
