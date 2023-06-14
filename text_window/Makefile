GBDK_HOME = /home/et/dev/gbdk/
CC = $(GBDK_HOME)bin/lcc
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = textwindow.gb

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f *.o *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm *.noi