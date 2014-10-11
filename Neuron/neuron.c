#include "neuron.h"
#include "../Point/point.h"
#include "../random/random.h"

Neuron * neuron_init(Neuron * neuron, int weight_length) {
    //Initialice neuron with a random standarized point
    point_standarize(  point_random( &(neuron->point) )  );  

    //Initialice neuron with random weights
    for(int w = 0; w < weight_length; w++ ){
        neuron->W_inverse[w] = urandom();
        neuron->W_direct[w] = urandom();

    }

    return neuron;
};


