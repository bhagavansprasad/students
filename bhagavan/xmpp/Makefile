#GCC:=mipsel-linux-uclibc-gcc
GCC:=gcc

#GCC:= mipsel-linux-uclibc-ar
GCC_ARCHIVE:=ar


GCC_FLAGS:=-g
GCC_FLAGS+=-Wall
GCC_FLAGS+=-Werror
#INC:=-I/usr/include
#INC+=-I/usr/include/i386-linux-gnu
INC+=-I/home/bhagavanp/sources/mipsel_stage/include
LDFLAGS=-L/home/bhagavanp/sources/mipsel_stage/lib -lcrypto -lm

cxmpp: config.o xmppc.o base64_utils.o utils.o main.o
	$(GCC) config.o xmppc.o base64_utils.o utils.o main.o $(GCC_FLAGS) $(LDFLAGS) -o  cxmpp
	$(GCC_ARCHIVE) rcs libxmppc.a config.o xmppc.o base64_utils.o utils.o  

config.o: config.c config.h
	$(GCC) -c config.c $(GCC_FLAGS)

xmppc.o: xmppc.c xmppc.h
	$(GCC) $(INC) -c xmppc.c $(GCC_FLAGS)

base64_utils.o: base64_utils.c
	$(GCC) -c base64_utils.c $(GCC_FLAGS)

utils.o: utils.c
	$(GCC) -c utils.c $(GCC_FLAGS)

main.o: main.c
	$(GCC) -c main.c $(GCC_FLAGS)

clean:
	rm -rf *.o
	rm -rf libxmppc.a
	rm -rf cxmpp
	
