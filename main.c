#include <stdio.h>
#include <stdlib.h> /* required for randomize() and random() */
#include <math.h> /*This is needed for the sqrt and pow functions to work*/

#define MAX_NEURON_NUMBER 10




typedef struct {
   double x;
   double y;
   double z;
} Point;


double random();
Point * random_point(Point *p);
Point * standarize(Point *p);
double calc_norm(Point p);




main() {

	Point Sphere[MAX_NEURON_NUMBER];

	int i;

	for(i = 0; i < MAX_NEURON_NUMBER; i++) {
		standarize(  random_point(&Sphere[i])  );
		printf("(%f, %f, %f) norm = %f \n", Sphere[i].x, Sphere[i].y, Sphere[i].z, calc_norm(Sphere[i]));
		
	}

	//initializice vector

    printf("Hello World");

};



double random(){
	//RAND_MAX is a constant defined in the rand module
	double r = 2 * (  (double)rand() / (double)RAND_MAX  ) - 0.5;
    return  r;
};


Point * random_point(Point *p) {

	//printf("%f", p->x);
	p->x = random();
	p->y = random();
	p->z = random();

	return p;
};


double calc_norm(Point p) {
	return sqrt(  pow(p.x, 2) + pow(p.y, 2) + pow(p.z, 2) ); 
};


Point * standarize(Point *p) {

	double norm = calc_norm(*p);
	p->x /= norm;
	p->y /= norm;
	p->z /= norm;

	return p;
};