CFLAGS ?= -O3
PREFIX ?= /usr/local
BINDIR ?= ${PREFIX}/bin

OBJS += cmul crc16 luhn morse parsc parsl pascal pngcsum visyear words xor

all: ${OBJS}

install: all
	install ${OBJS} ${DESTDIR}${BINDIR}

uninstall:
	rm -f ${OBJS:%=${DESTDIR}${BINDIR}/%}

clean:
	rm -f ${OBJS}

