#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "blink.h"

void init_leds(ledData* leds)
{

  int fd;
  int i;
  
  for (i = 0; i < NR_LEDS; i++)
    {
      snprintf(leds[i].trigger, FILENAME_LEN, "/sys/class/leds/beaglebone:green:usr%d%s", i, "/trigger");
                                              
      snprintf(leds[i].brightness, FILENAME_LEN, "/sys/class/leds/beaglebone:green:usr%d%s", i, "/brightness");
      
      /* Turn off all triggers for led (set trigger to none).*/
      fd = open(leds[i].trigger, O_RDWR);
      write(fd,"none",4);
      close(fd);
      
      /* Open brightness file in read/write mode for led. */
      /* Save file descriptor for brightness. */
      leds[i].led_fd = open(leds[i].brightness, O_RDWR);
      

      /* Turn off leds 0, 2 ... and turn on leds 1, 3 ... */
      if ((i % 2) == 0)
  	{
  	  ledOff(leds[i].led_fd);
  	  leds[i].led_on = OFF;
  	} else
  	{
  	  ledOn(leds[i].led_fd);
  	  leds[i].led_on = ON;
      }
    }
}


int toggleLed(int fd, int on)
{

  if (!on) {
    ledOn(fd);
    on = ON;
  }
  else {
    ledOff(fd);
    on = OFF;
  }
  return on;
}


void ledOff(int fd)
{
  /* Turn LED off */
  write(fd,"0",1);
}

void ledOn(int fd)
{
  /* Turn LED on */
  write(fd,"1",1);
}
