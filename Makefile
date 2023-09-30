CFLAGS ?= -O3
PREFIX ?= /usr/local
BINDIR ?= ${PREFIX}/bin

all: crc16 pngcsum pascal parsc parsl cmul words

install: all
	install crc16 ${DESTDIR}${BINDIR}
	install pngcsum ${DESTDIR}${BINDIR}
	install pascal ${DESTDIR}${BINDIR}
	install parsc ${DESTDIR}${BINDIR}
	install parsl ${DESTDIR}${BINDIR}
	install cmul ${DESTDIR}${BINDIR}
	install words ${DESTDIR}${BINDIR}

uninstall:
	rm -f \
		${DESTDIR}${BINDIR}/crc16   \
		${DESTDIR}${BINDIR}/pngcsum \
		${DESTDIR}${BINDIR}/pascal  \
		${DESTDIR}${BINDIR}/parsc   \
		${DESTDIR}${BINDIR}/parsl   \
		${DESTDIR}${BINDIR}/cmul    \
		${DESTDIR}${BINDIR}/words

clean:
	rm -f crc16 pngcsum pascal parsc \
		parsl cmul words

