# Project name
TARGET=vd

# Directories
ODIR=obj
IDIR=inc
SDIR=src

# Compiler stuff
CC=g++
CFLAGS=-Wall -g -Werror -std=c++11 $(DEBUG)
CINCL=-I$(IDIR)
CLIB=-L/usr/lib -lSDL2

# Extra
MK_DIR=mkdir -p
RM_DIR=rmdir
RM_FIL=rm -f

# Source .cpp
_SRC=vd.cpp point.cpp variables.cpp linesegment.cpp circle.cpp camera.cpp
SRC=$(patsubst %.cpp, $(SDIR)/%.cpp, $(_SRC))

# Dependencies .h
_DEPS=vd.h point.h variables.h linesegment.h circle.h camera.h
DEPS=$(patsubst %.h, $(IDIR)/%.h, $(_DEPS))

# Objects .o
_OBJ=vd.o point.o variables.o linesegment.o circle.o camera.o
OBJ=$(patsubst %.o, $(ODIR)/%.o, $(_OBJ))

all: directories $(TARGET)

directories: $(ODIR)

$(ODIR):
	[ -d "$(ODIR)" ] || $(MK_DIR) $(ODIR)

$(TARGET): $(OBJ)
	$(CC) $(CINCL) $(CFLAGS) $(CLIB) -o $@ $(SRC)

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) $(CINCL) $(CFLAGS) $(CLIB) -c -o $@ $< 

.PHONY: clean
clean: clean_files clean_directories

clean_files:
	$(RM_FIL) $(OBJ) $(TARGET)

clean_directories:
	[ ! -d "$(ODIR)" ] || $(RM_DIR) $(ODIR)
