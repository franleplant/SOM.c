SOM.c
=====

## Requirements

```sh
#download git submodules
git submodule init
git submodule update
```


## Run the code



```bash
make
./main
```

## Make tasks

- `make`: compile and run the program
- `make test`: run tests!
- `make debug`: compile without optimization and open gdb debugger
- `make verbose`: compile normally and run it with Valgrind to see more verbose error output
- `make clean`: removes compiled files and clear the screen


## Writting test

1. Visit `random/test.c` and create an analog file for the functionality that you want to test.
2. Visit `test.conf.c` and add the proper header file of the new functionality being tested and add the SUITE to the suite list and as an `extern` variable.
3. Visit `Makefile` and add to the `TEST_OBJECTS` variable the file containing the tests and the SUITE.
4. Run `make test` and be happy!

## Timing


Is important to know how much time does the program takes to calculate
all the iterations.

To measure it run:

```bash
make
time ./main
```

Focus on the `real` field, that is the time that it took the program to return.


## Performance

C is pretty good at making a lot of calculations, but its really slow (as you might suspect)
on printing values, so avoid making a lot of printing because its very time consuming.


## Debugging

The VM comes with GDB which is the debugger for C.
Use GDB instead of old printf.



To debug:
```bash

# Run debug make task
make debug
# On gdb console
# Create a breakpoint on line 74
break 74
# run the program
run
# It will stop on the breakpoint
# you can inspect any variable at this point
print some_var
# Continue
cont
# Repeat and Enjoy!
```

Links:

- [Official Tuto](http://www.cs.cmu.edu/~gilpin/tutorial/)
- [Non-Official nice tuto](http://www.thegeekstuff.com/2010/03/debug-c-program-using-gdb/)


## More info

Checkout our [wiki](https://github.com/franleplant/SOM.c/wiki)
for more info!
