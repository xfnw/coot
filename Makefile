CFLAGS ?= -O3
PREFIX ?= /usr/local
BINDIR ?= ${PREFIX}/bin
WASMCC ?= /opt/wasi-sdk/bin/clang
WFLAGS ?= --target=wasm32-wasi --sysroot /usr/share/wasi-sysroot

OBJS += cmul crc16 luhn morse parsc parsl pascal visyear words xor

all: ${OBJS}

wasi: ${OBJS:%=%.wasm}

%.wasm: %.c
	${WASMCC} ${WFLAGS} ${CFLAGS} -o $@ $<

install: all
	install ${OBJS} ${DESTDIR}${BINDIR}

uninstall:
	rm -f ${OBJS:%=${DESTDIR}${BINDIR}/%}

clean:
	rm -f ${OBJS} ${OBJS:%=%.wasm}

