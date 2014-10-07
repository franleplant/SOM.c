#include <math.h> /* sqrt(), pow() */
#include "../random/random.h"
#include "point.h"


/*
	point_init
		summary: Load a point with certain coordinates
*/
Point * point_init(Point *p, double x, double y, double z) {
	p->x = x;
	p->y = y;
	p->z = z;

    return p;
};



/*
	random_point
		summary: Load a point with random coordinates
*/
Point * random_point(Point *p) {

	p->x = random_sphere_coord();
	p->y = random_sphere_coord();
	p->z = random_sphere_coord();

	return p;
};

/*
	calc_norm
		summary: calculate and return the norm of a given 3d point.
*/
double calc_norm(Point p) {

	return sqrt(  pow(p.x, 2) + pow(p.y, 2) + pow(p.z, 2) ); 
};


/*
	point_standarize
		summary: Standarize a given point
*/
Point * point_standarize(Point *p) {

	double norm = calc_norm(*p);
	p->x /= norm;
	p->y /= norm;
	p->z /= norm;

	return p;
};


