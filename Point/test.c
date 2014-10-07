#include "point.h"
#include "../lib/greatest/greatest.h"




SUITE(point_module);

TEST test_point_struct() {
    Point p;
    p.x = 1;
    p.y = 2;
    p.z = 3;
    

    ASSERTm("it should create a Point struct that contains x attribute", p.x == 1); 
    ASSERTm("it should create a Point struct that contains y attribute", p.y == 2); 
    ASSERTm("it should create a Point struct that contains z attribute", p.z == 3); 
    PASS();
}

TEST test_point_init() {
    Point p;
    Point * q; 

    q = point_init(&p, 1, 2, 3);

    ASSERTm("it should create a Point struct that contains x attribute", p.x == 1); 
    ASSERTm("it should create a Point struct that contains y attribute", p.y == 2); 
    ASSERTm("it should create a Point struct that contains z attribute", p.z == 3); 

    ASSERTm("it should return a pointer to the Point struct", p.x == q->x);
    ASSERTm("it should return a pointer to the Point struct", p.y == q->y);
    ASSERTm("it should return a pointer to the Point struct", p.z == q->z);

    PASS();
}

TEST test_random_point() {
    Point p;
    Point * q;

    q = random_point(&p);

    ASSERTm("it should create a Point struct with random x attribute", p.x > -100);
    ASSERTm("it should create a Point struct with random y attribute", p.y > -100);
    ASSERTm("it should create a Point struct with random z attribute", p.z > -100);

    ASSERTm("it should return a pointer to the Point struct", p.x == q->x);
    ASSERTm("it should return a pointer to the Point struct", p.y == q->y);
    ASSERTm("it should return a pointer to the Point struct", p.z == q->z);

    PASS();
}



TEST test_calc_norm() {
    Point p;
    double res;

    point_init(&p, 1, 2, 2);
    res = calc_norm(p);

    ASSERTm("it should return the vectorial norm of a point p", res == 3 );

    PASS();
}




SUITE(point_module) {
    RUN_TEST(test_point_struct);
    RUN_TEST(test_point_init);
    RUN_TEST(test_random_point);
    RUN_TEST(test_calc_norm);
}
