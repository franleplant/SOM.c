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
    
    point_init(&p, 1, 2, 3);


    ASSERTm("it should create a Point struct that contains x attribute", p.x == 1); 
    ASSERTm("it should create a Point struct that contains y attribute", p.y == 2); 
    ASSERTm("it should create a Point struct that contains z attribute", p.z == 3); 
    PASS();
}


SUITE(point_module) {
    RUN_TEST(test_point_struct);
    RUN_TEST(test_point_init);
}
