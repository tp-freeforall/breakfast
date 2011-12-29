SOURCES=toggle.c bslskey.S

CCFLAGS=-mmcu=msp430f235
LDFLAGS=-T msp430.x

CC=msp430-gcc
OBJCOPY=msp430-objcopy
ODIR=bin
EXES=$(SOURCES:.c=.bin)
EXES_=$(patsubst %,$(ODIR)/%,$(EXES))
HEXES=$(SOURCES:.c=.hex)
HEXES_=$(patsubst %,$(ODIR)/%,$(HEXES))


all: $(ODIR) $(HEXES_) $(EXES_)

$(ODIR):
	mkdir -p $(ODIR)

$(ODIR)/%.hex: $(ODIR)/%.bin
	$(OBJCOPY) -I elf32-msp430 -O ihex $< $@

$(ODIR)/%.bin: %.c 
	$(CC) $(CCFLAGS) $(LDFLAGS) $< -o $@ 

clean:
	rm -rf $(ODIR)

