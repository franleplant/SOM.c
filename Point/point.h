#ifndef POINT_H
#define POINT_H





typedef struct {
   double x;
   double y;
   double z;
} Point;


Point * point_random(Point *p);
double  point_calc_norm(Point *p);
Point * point_standarize(Point *p);
Point * point_init(Point *p, double x, double y, double z);




#endif
