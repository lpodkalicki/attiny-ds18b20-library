# DS18B20 Library
This is tinyAVR (ATtiny13, ATtiny25, ATtiny45, ATtiny85, etc.) library for DS18B20 temperature sensor. Supports both positive and negative temperature reading.

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
	int16_t t;

	while (1) {
		t = DS18B20_read(DS18B20_PIN);
		uart_putt(t);
		_delay_ms(1000);
	}
}

```

## Example Logs

```bash
[09:30:38:929] 23.5 st. C␊
[09:30:40:008] 23.4 st. C␊
[09:30:41:087] 23.3 st. C␊
[09:30:42:165] 23.5 st. C␊
[09:30:43:243] 23.5 st. C␊
[09:30:44:322] 23.3 st. C␊
[09:30:45:401] 23.3 st. C␊
[09:30:46:478] 23.5 st. C␊
[09:30:47:557] 23.4 st. C␊
[09:30:48:634] 23.3 st. C␊
[09:30:49:712] 23.3 st. C␊
[09:30:50:790] 23.3 st. C␊
[09:30:51:868] 23.4 st. C␊
```

