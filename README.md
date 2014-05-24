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

> **NOTE ABOUT OPTIMIZATION:** you may want to remove `-O3` flag from `makefile`
to inspect correctly the program, sometimes the optimization distorts completely your code
in order to make it faster potentially given you troubles to debug.


To debug:
```bash

# compile
make
# open gdb
gdb main
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