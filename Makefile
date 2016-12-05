CFLAGS ?= -Wall -pedantic -g
LDFLAGS ?= 

PROGRAM = blink
OBJFILES = blink.o leds.o

$(PROGRAM): $(OBJFILES)
	$(CC)  $^  $(LDFLAGS)  -o $@

clean:
	\rm -f   *.o  $(PROGRAM)  *~ 
