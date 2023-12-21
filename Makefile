CFLAGS ?= -O3
PREFIX ?= /usr/local
BINDIR ?= ${PREFIX}/bin

OBJS += crc16 pngcsum pascal parsc parsl cmul words morse

all: ${OBJS}

install: all
	install ${OBJS} ${DESTDIR}${BINDIR}

uninstall:
	rm -f ${OBJS:%=${DESTDIR}${BINDIR}/%}

clean:
	rm -f ${OBJS}

