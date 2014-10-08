#ifndef NEURON_H
#define NEURON_H


typedef struct {

    double W_inverse[MAX_SYNAPSIS_NUMBER];
    double W_direct[MAX_SYNAPSIS_NUMBER]; 
    Point point;

} Neuron;



#endif
