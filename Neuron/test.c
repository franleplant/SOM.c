#include "neuron.h"
#include "../lib/greatest/greatest.h"



SUITE(neuron_module);

TEST test_neuron_struct() {
    Neuron n;
    n.W_inverse[0] = 1;
    n.W_direct[1]  = 1;


    point_init( &(n.point), 1, 1, 1); 

    ASSERTm("it should create a Neuron struct with W_inverse attribute", n.W_inverse[0] == 1); 
    ASSERTm("it should create a Neuron struct with W_direct attribute", n.W_direct[1] == 1); 
   
    ASSERTm("it should create a Neuron struct with a Point attribute ", n.point.x  == 1); 
    ASSERTm("it should create a Neuron struct with a Point attribute ", n.point.y  == 1); 
    ASSERTm("it should create a Neuron struct with a Point attribute ", n.point.z  == 1); 

    PASS();
}

TEST test_neuron_init() {
    Neuron n;
    Neuron * q;

    q = neuron_init(&n, 3);

    //Assert that the weights are between boundaries and that they are in fact doubles
    ASSERTm("it should create a Neuron structure with random W_direct",  n.W_direct[0]>-1  && n.W_direct[1]>-1  && n.W_direct[2]>-1); 
    ASSERTm("it should create a Neuron structure with random W_inverse", n.W_inverse[0]>-1 && n.W_inverse[1]>-1 && n.W_inverse[2]>-1); 


    //Assert the existance of the point in the fact that they are doubles and thus comparable
    ASSERTm("it should return a pointer to the Neuron struct's point and it should create a random point", n.point.x == q->point.x);
    ASSERTm("it should return a pointer to the Neuron struct's point and it should create a random point", n.point.y == q->point.y);
    ASSERTm("it should return a pointer to the Neuron struct's point and it should create a random point", n.point.z == q->point.z);

    ASSERTm("it should return a pointer to the Neuron struct's direct weights", n.W_direct[0] == q->W_direct[0]);
    ASSERTm("it should return a pointer to the Neuron struct's direct weights", n.W_direct[1] == q->W_direct[1]);
    ASSERTm("it should return a pointer to the Neuron struct's direct weights", n.W_direct[2] == q->W_direct[2]);



    ASSERTm("it should return a pointer to the Neuron struct's inverse weights", n.W_inverse[0] == q->W_inverse[0]);
    ASSERTm("it should return a pointer to the Neuron struct's inverse weights", n.W_inverse[1] == q->W_inverse[1]);
    ASSERTm("it should return a pointer to the Neuron struct's inverse weights", n.W_inverse[2] == q->W_inverse[2]);

    PASS();
}



SUITE(neuron_module) {
    RUN_TEST(test_neuron_struct);
    RUN_TEST(test_neuron_init);

}
