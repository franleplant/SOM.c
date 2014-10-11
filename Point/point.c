#include <math.h> /* sqrt(), pow() */
#include "../random/random.h"
#include "point.h"


/*
    Load a point with certain coordinates
*/
inline Point * point_init(Point *p, double x, double y, double z) {
	p->x = x;
	p->y = y;
	p->z = z;

    return p;
};



/*
    Load a point with random coordinates
*/
inline Point * point_random(Point *p) {

	p->x = random_sphere_coord();
	p->y = random_sphere_coord();
	p->z = random_sphere_coord();

	return p;
};

/*
    calculate and return the norm of a given 3d point.
*/
inline double point_calc_norm(Point * p) {
	return sqrt(  pow(p.x, 2) + pow(p.y, 2) + pow(p.z, 2) ); 
};


/*
    Standarize a given point
*/
inline Point * point_standarize(Point *p) {

	double norm = point_calc_norm(*p);
	p->x /= norm;
	p->y /= norm;
	p->z /= norm;

	return p;
};
