#ETIENNE (づ｡◕‿‿◕｡)づ PENAULT#

SRC	= $(wildcard *.c)
OBJS	= $(SRC:.c=.o)
HEADER	= $(wildcard *.h)
OUT		= nn.out
CC	 	= gcc

CFLAGS	= -Ofast -Wall -W

macLFLAGS	=
linuxLFLAGS	= 

OS := $(shell uname)


all: $(OBJS)
ifeq ($(OS), Darwin)
	$(CC) $(OBJS) -o $(OUT) $(macLFLAGS)
else
	$(CC) $(OBJS) -o $(OUT) $(linuxLFLAGS)
endif


%.o:	%.c %.p
	$(CC) -c $< $(CFLAGS)

%.o:	%.c %.h
	$(CC) -c $< $(CFLAGS)

%.o:	%.c
	$(CC) -c $< $(CFLAGS)


clean:
	rm -f $(OBJS)

cleanall:
	rm -f $(OBJS) $(OUT)
