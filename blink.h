#ifndef BLINK_H
#define BLINK_H

#define ON 1
#define OFF !ON

#define FILENAME_LEN 80

typedef struct _ledData
{
  int led_fd; /* file descriptor for brightness file */
  int led_on; /* ON (1) or OFF (0) */ 
  char trigger[FILENAME_LEN];  /* led trigger file */
  char brightness[FILENAME_LEN]; /* led brightness file */
} ledData;

void init_leds(ledData* leds);

int toggleLed(int fd, int on);
void ledOff(int fd);
void ledOn(int fd);

#define NR_LEDS 4 /* max number of leds is 4 on the board */

#endif
