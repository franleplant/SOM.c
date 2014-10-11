#ifndef NEURON_H
#define NEURON_H

#include "../Point/point.h"

// Defaults to facilitate testing
#ifndef MAX_SYNAPSIS_NUMBER
#define MAX_SYNAPSIS_NUMBER 3
#endif




typedef struct {

    double W_inverse[MAX_SYNAPSIS_NUMBER];
    double W_direct[MAX_SYNAPSIS_NUMBER]; 
    Point point;

} Neuron;




Neuron * neuron_init(Neuron * neuron, int weight_length);

#endif
