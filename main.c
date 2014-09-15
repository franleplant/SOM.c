#include <stdio.h>
#include <math.h> /* sqrt(), pow() */
#include "Point/point.h"
#include "random/random.h"


#define MAX_NEURON_NUMBER 270
#define MAX_SYNAPSIS_NUMBER 637
#define MAX_ITERATION_NUMBER 3000
#define PI 3.14159265358979323846






/*
Neuron typedef and functions
*/


typedef struct {

  double W_inverse[MAX_SYNAPSIS_NUMBER];
  double W_direct[MAX_SYNAPSIS_NUMBER]; 
  Point point;

} Neuron;



//TODO: change this fn's name to something like calc_sphere_neuron_distribution
void calc_neuron_distribution(Neuron * neurons, int length) {

	
	// Electrostatic repulsion Force
	Point fer_i, distance;
	float dltt = 0.1;
	double cos_ij = 0;
	double cos_ij_mean = 0;
	double distance_norm;
	int i, j, iter;

	//initializice vector
	for(i = 0; i < length; i++) {
		standarize(  random_point(&(neurons[i].point))  );	
	};


	//Calculate the neuron distribution
	for(iter = 0; iter < MAX_ITERATION_NUMBER; iter++){
		for(i = 0; i < length; i++) {

			point_init(&fer_i, 0, 0, 0);

			for(j = 0; j < length; j++) {

				distance.x = neurons[i].point.x - neurons[j].point.x;
				distance.y = neurons[i].point.y - neurons[j].point.y;
				distance.z = neurons[i].point.z - neurons[j].point.z;

				distance_norm = calc_norm(distance);

				if (distance_norm > 0) {
					fer_i.x += distance.x / distance_norm;
					fer_i.y += distance.y / distance_norm;
					fer_i.z += distance.z / distance_norm;
				};

				if (iter == 2999) {
					//Calculate angular cosine between Neurons i and j
					cos_ij = neurons[i].point.x * neurons[j].point.x + 
                                                 neurons[i].point.y * neurons[j].point.y + 
                                                 neurons[i].point.z * neurons[j].point.z;
					cos_ij_mean = ( cos_ij_mean + cos_ij ) / 2;					
				};
			};

			//Calculate the position change due to the Electrostatic Repulsion Force aceleration
			neurons[i].point.x += fer_i.x * pow(dltt, 2);
			neurons[i].point.y += fer_i.y * pow(dltt, 2);
			neurons[i].point.z += fer_i.z * pow(dltt, 2);

			standarize(  &(neurons[i].point)  );
		};
	};


	double sin_ij_mean = sqrt(  1 - pow(cos_ij_mean, 2));
	double angle_mean = atan( sin_ij_mean / cos_ij_mean );

	printf("mean angle: %f  \n", angle_mean * 180/PI);
};

void init_neurons_weights(Neuron * neurons, int length, int weight_length){

  for(int i = 0; i < length; i++) {
    for(int w = 0; w < weight_length; w++ ){
      neurons[i].W_inverse[w] = random();
      neurons[i].W_direct[w] = random();

    }

  }

  return;
};

int main() {

  Neuron neurons[MAX_NEURON_NUMBER];

  //Pass the reference to the first element on the Neuron Array, the func
  // will work with the rest.
  calc_neuron_distribution(&neurons[0], MAX_NEURON_NUMBER);

  init_neurons_weights(&neurons[0], MAX_NEURON_NUMBER, MAX_SYNAPSIS_NUMBER); 

  return 0;	
};



