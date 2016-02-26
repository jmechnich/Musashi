EXENAME          = sim

ifdef SystemRoot
EXE     = .exe
EXEPATH = .\\
OSD_C   = osd_dos.c
else
EXEPATH    = ./
OSD_C      = osd_linux.c
MUSASHIDIR = ../
endif

OSDFILES         = $(OSD_C)
MAINFILES        = sim.c
MUSASHIFILES     = m68kcpu.c m68kdasm.c
MUSASHIGENCFILES = m68kops.c m68kopac.c m68kopdm.c m68kopnz.c
MUSASHIGENHFILES = m68kops.h
MUSASHIGENERATOR = m68kmake

.CFILES   = $(MAINFILES) $(OSDFILES) $(MUSASHIFILES) $(MUSASHIGENCFILES)
.OFILES   = $(.CFILES:%.c=%.o)

CC        = gcc
WARNINGS  = -Wall -pedantic
CFLAGS    = $(WARNINGS)
LFLAGS    = $(WARNINGS)

TARGET = $(EXENAME)$(EXE)

DELETEFILES = $(MUSASHIGENCFILES) $(MUSASHIGENHFILES) $(.OFILES) $(TARGET) $(MUSASHIGENERATOR)$(EXE)


all: $(TARGET)

clean:
	rm -f $(DELETEFILES)

$(TARGET): $(MUSASHIGENHFILES) $(.OFILES) makefile
	$(CC) -o $@ $(.OFILES) $(LFLAGS)

$(MUSASHIGENCFILES) $(MUSASHIGENHFILES): $(MUSASHIGENERATOR)$(EXE)
	$(EXEPATH)$(MUSASHIGENERATOR)$(EXE)

$(MUSASHIGENERATOR)$(EXE):  $(MUSASHIGENERATOR).c
	$(CC) -o  $(MUSASHIGENERATOR)$(EXE)  $(MUSASHIGENERATOR).c
