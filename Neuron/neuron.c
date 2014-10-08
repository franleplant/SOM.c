#include "neuron.h"


Neuron * neuron_init_weights(Neuron * neuron, int weight_length) {

    for(int w = 0; w < weight_length; w++ ){
        neuron.W_inverse[w] = urandom();
        neuron.W_direct[w] = urandom();

    }

    return neuron;
};


