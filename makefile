P = main
OBJECTS= main.c
CFLAGS = -g -Wall $(OPTIMIZATION) 
LDLIBS= -lm
CC=c99
OPTIMIZATION=-O3


all: $(P)


$(P): clean
	$(CC) $(CFLAGS) $(OBJECTS) -o $(P)  $(LDLIBS)
	./$(P)


# Time tasks
# Needs to process the output into a more understandable way
time: $(P)
	time ./$(P)

# Compiles with no optimization
# Starts gdb

# Target specific variable
debug: OPTIMIZATION=-O0

debug: clean $(P)
	gdb $(P)



# verbose out put
verbose: clean $(P)
	valgrind ./$(P)


clean:
	rm -f $(P); clear


# $@ the full target filename
# $* The target file with the suffix cut off. So if the target is  prog.o
# $< The name of the file that caused this target to get triggered and made. 

