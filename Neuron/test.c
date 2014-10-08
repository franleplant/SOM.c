#include "neuron.h"
#include "../lib/greatest/greatest.h"



SUITE(neuron_module);

TEST test_neuron_struct() {
    Neuron n;
    n.W_inverse[0] = 1;
    n.W_direct[1]  = 1;
    

    ASSERTm("it should create a Neuron struct with W_inverse attribute", n.W_inverse[0] == 1); 
    ASSERTm("it should create a Neuron struct with W_direct attribute", n.W_direct[1] == 1); 



    PASS();
}
/*
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

*/

SUITE(neuron_module) {
    RUN_TEST(test_neuron_struct);
}
