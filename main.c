#include <stdio.h>
#include <stdlib.h> /* randomize(), random() */
#include <math.h> /* sqrt(), pow() */

#define MAX_NEURON_NUMBER 270
#define MAX_ITERATION_NUMBER 3000


typedef struct {
   double x;
   double y;
   double z;
} Point;

//Prototypes
double random();
Point * random_point(Point *p);
Point * standarize(Point *p);
double calc_norm(Point p);
void point_init(Point *p, double x, double y, double z);




int main() {

	Point Neuron[MAX_NEURON_NUMBER];

	int i;
	int iter;
	int j;
	// Electrostatic repulsion Force
	Point fer_i;
	Point distance;
	double distance_norm;
	float dltt = 0.1;

	//Initialize angular cos max placeholder
	double cos_ij_max = -1;
	double cos_ij = 0;




	//initializice vector
	for(i = 0; i < MAX_NEURON_NUMBER; i++) {
		standarize(  random_point(&Neuron[i])  );	
	};


	//Calculate the neuron distribution
	for(iter = 0; iter < MAX_ITERATION_NUMBER; iter++){

		//printf("iteration %d \n", iter);

		for(i = 0; i < MAX_NEURON_NUMBER; i++) {

			point_init(&fer_i, 0, 0, 0);

			for(j = 0; j < MAX_NEURON_NUMBER; j++) {

				distance.x = Neuron[i].x - Neuron[j].x;
				distance.y = Neuron[i].y - Neuron[j].y;
				distance.z = Neuron[i].z - Neuron[j].z;

				distance_norm = calc_norm(distance);

				if (distance_norm > 0) {

					fer_i.x += distance.x / distance_norm;
					fer_i.y += distance.y / distance_norm;
					fer_i.z += distance.z / distance_norm;
				};

				
				if (iter == 2999) {
					//Calculate angular cosine between Neurons i and j
					cos_ij = Neuron[i].x * Neuron[j].x + Neuron[i].y * Neuron[j].y + Neuron[i].z * Neuron[j].z;

					//Max calc
					if (cos_ij > cos_ij_max) {
						cos_ij_max = cos_ij;
					};					
				};
	
			};

			//Calculate the position change due to the Electrostatic Repulsion Force aceleration
			Neuron[i].x += fer_i.x * pow(dltt, 2);
			Neuron[i].y += fer_i.y * pow(dltt, 2);
			Neuron[i].z += fer_i.z * pow(dltt, 2);

			standarize(  &Neuron[i]  );
		}

	}

	double a = 1 - pow(cos_ij_max, 2);
	double b = abs(a) < 1e-12 ? 0 : a ;
	
	double sin_ij_max = sqrt((double)  b);

	printf("max angle: %f      %f \n", sin_ij_max, cos_ij_max);	

	double max_angle = atan( sin_ij_max / cos_ij_max );


	 //sqrt(abs(x) < 1e-12 ? 0 : x); 

	printf("max angle: %f \n", max_angle);

	return 0;	
};




double random(){
	//RAND_MAX is a constant defined in the rand module
	double r = 2 * (  (double)rand() / (double)RAND_MAX  ) - 0.5;
    return  r;
};


Point * random_point(Point *p) {

	//printf("%f", p->x);
	p->x = random();
	p->y = random();
	p->z = random();

	return p;
};


double calc_norm(Point p) {

	return sqrt(  pow(p.x, 2) + pow(p.y, 2) + pow(p.z, 2) ); 
};


Point * standarize(Point *p) {

	double norm = calc_norm(*p);
	p->x /= norm;
	p->y /= norm;
	p->z /= norm;

	return p;
};

void point_init(Point *p, double x, double y, double z) {
	p->x = x;
	p->y = y;
	p->z = z;
};
