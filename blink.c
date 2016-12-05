#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "blink.h"

int main()
{
  int i, j;
  ledData leds[NR_LEDS];

  printf("Flashing LEDs!\n");
  init_leds(leds);

  /* Flash with LED for 60 seconds */
  for(i = 0; i < 60; i++)
    {
      for ( j = 2; j < NR_LEDS; j++)  /* led 2 and 3 */
	{
	  leds[j].led_on = toggleLed(leds[j].led_fd, leds[j].led_on);
	}
      sleep(1);
    }

  for ( j = 0; j < NR_LEDS; j++)
    {
      ledOff(leds[j].led_fd);
      close(leds[j].led_fd);
    }
  printf("Turning off LEDs!\n");
  exit(EXIT_SUCCESS);
}
