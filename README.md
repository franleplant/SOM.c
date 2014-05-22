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
