# Project name
TARGET=vectordrawer

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

# Source
_SRC=coords.cpp point.cpp vd.cpp vector.cpp vectordrawer.cpp
SRC=$(patsubst %.cpp, $(SDIR)/%.cpp, $(_SRC))

# Dependencies
_DEPS=point.h vector.h coords.h vectordrawer.h
DEPS=$(patsubst %.h, $(IDIR)/%.h, $(_DEPS))

# Objects
_OBJ=point.o vector.o coords.o vd.o vectordrawer.o
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
