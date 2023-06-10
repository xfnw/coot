CFLAGS ?= -O3
PREFIX ?= /usr/local
BINDIR ?= ${PREFIX}/bin

all: crc16 pngcsum pascal

install: all
	install crc16 ${DESTDIR}${BINDIR}
	install pngcsum ${DESTDIR}${BINDIR}
	install pascal ${DESTDIR}${BINDIR}

uninstall:
	rm -f \
		${DESTDIR}${BINDIR}/crc16 \
		${DESTDIR}${BINDIR}/pngcsum \
		${DESTDIR}${BINDIR}/pascal

clean:
	rm -f crc16 pngcsum pascal

