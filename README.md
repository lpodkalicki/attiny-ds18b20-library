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

## Example Logs

```bash
[10:10:08:244] 24.06 st. C␊
[10:10:09:323] 24.00 st. C␊
[10:10:10:401] 24.06 st. C␊
[10:10:11:479] 23.93 st. C␊
[10:10:12:559] 24.00 st. C␊
[10:10:13:637] 23.81 st. C␊
[10:10:14:716] 23.87 st. C␊
[10:10:15:795] 23.81 st. C␊
[10:10:16:875] 23.68 st. C␊
[10:10:17:954] 23.68 st. C␊
[10:10:19:032] 23.56 st. C␊
[10:10:20:111] 23.68 st. C␊
[10:10:21:189] 23.56 st. C␊
[10:10:22:268] 23.50 st. C␊
[10:10:23:346] 23.56 st. C␊
[10:10:24:425] 23.62 st. C␊
[10:10:25:503] 23.50 st. C␊
[10:10:26:581] 23.50 st. C␊
```
