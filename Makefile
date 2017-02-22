# Makefile for building the PandoraUI
# (c) 2017 Benedikt Muessig <benedikt.muessig@gmail.com>

PLATFORM=pc
ROOTDIR=

ifeq ($(PLATFORM),arm)
	ROOTDIR=/home/bmuessig/Pandora/target
	export PKG_CONFIG_PATH=$(LD_LIBRARY_PATH)/pkgconfig
endif

export LD_LIBRARY_PATH=$(ROOTDIR)/lib

IDIR=./inc
ODIR=./obj
SDIR=./src
LDIR=$(LD_LIBRARY_PATH)

CHAIN=
CHAINDIR=/usr

ifeq ($(PLATFORM),arm)
	CHAIN=armarmv5te-unknown-linux-gnueabi-
	CHAINDIR=/home/bmuessig/x-tools/armarmv5te-unknown-linux-gnueabi
endif

CC=$(CHAINDIR)/bin/$(CHAIN)gcc
CXX=$(CHAINDIR)/bin/$(CHAIN)g++
LD=$(CHAINDIR)/bin/$(CHAIN)ld
AS=$(CHAINDIR)/bin/$(CHAIN)as
AR=$(CHAINDIR)/bin/$(CHAIN)ar
STRIP=$(CHAINDIR)/bin/$(CHAIN)strip
RANLIB=$(CHAINDIR)/bin/$(CHAIN)-ranlib

CFLAGS=`pkg-config --cflags sdl` `pkg-config --cflags SDL_image` `pkg-config --cflags SDL_ttf` -I$(IDIR) -I$(ROOTDIR)/include
LDFLAGS=`pkg-config --libs sdl` `pkg-config --libs SDL_image` `pkg-config --libs SDL_ttf` `pkg-config --libs freetype2` `pkg-config --libs libpng` `pkg-config --libs zlib`
STRIPFLAGS=--strip-unneeded

ifeq ($(PLATFORM),arm)
	CFLAGS+=-DARM
	LDFLAGS+=--static
endif

_DEPS=main.h params.h ui.h styles.h
_OBJ=main.o params.o ui.o styles.o

DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

.PHONY: clean all

all: pdui.elf pdui.min.elf

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

pdui.elf: $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

pdui.min.elf: pdui.elf
	$(STRIP) -o $@ $^ $(STRIPFLAGS)

clean:
	rm -f $(ODIR)/*.o *~ *.elf
