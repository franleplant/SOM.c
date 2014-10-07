#ifndef POINT_H
#define POINT_H





typedef struct {
   double x;
   double y;
   double z;
} Point;


Point * random_point(Point *p);
double calc_norm(Point p);
Point * standarize(Point *p);
Point * point_init(Point *p, double x, double y, double z);




#endif
