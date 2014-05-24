SOM.c
=====

### Run the code


In the [SOM.c-box](https://github.com/franleplant/SOM.c-box) environment:


```bash
vagrant up && vagrant ssh
cd shared/SOM
make
./main
```

## Make tasks

- `make`: compile and run the program
- `make debug`: compile without optimization and open gdb debugger
- `make verbose`: compile normally and run it with Valgrind to see more verbose error output
- `make clean`: removes compiled files and clear the screen


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
