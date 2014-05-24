P = main
OBJECTS= main.c
CFLAGS = -g -Wall $(OPTIMIZATION) 
LDLIBS= -lm
CC=c99
OPTIMIZATION=-O3


all: $(P)

# $@ the full target filename
# $* The target file with the suffix cut off. So if the target is  prog.o
# $< The name of the file that caused this target to get triggered and made. 

$(P): $(OBJECTS)
	

# Compiles with no optimization
# Starts gdb
debug: $(OBJECTS)
	OPTIMIZATION=-O0
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $*.c
	gdb $(P)

clean:
	rm -f $(P)

