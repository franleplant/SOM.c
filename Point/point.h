#ifndef POINT_H
#define POINT_H



#include "point_struct.h"


Point * random_point(Point *p);
double calc_norm(Point p);
Point * standarize(Point *p);
void point_init(Point *p, double x, double y, double z);




#endif