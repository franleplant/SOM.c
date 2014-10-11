P= main
OBJECTS= Neuron/neuron.c Point/point.c random/random.c 
MAIN= main.c
CFLAGS = -g -Wall $(OPTIMIZATION) 
LDLIBS= -lm
CC=c99
OPTIMIZATION=-O3

TEST_MAIN= test.conf.c
TEST_OBJECTS= $(wildcard **/test.c) 

all: $(P)


$(P): clean
	$(CC) $(CFLAGS) $(OBJECTS) $(MAIN) -o $(P)  $(LDLIBS)


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
	rm -f $(P) test; clear

test: clean 
	$(CC) $(OBJECTS) $(TEST_OBJECTS) $(TEST_MAIN) -o test $(LDLIBS)
	./test -v | lib/greatest/greenest

# $@ the full target filename
# $* The target file with the suffix cut off. So if the target is  prog.o
# $< The name of the file that caused this target to get triggered and made. 

