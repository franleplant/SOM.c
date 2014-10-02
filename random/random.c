#include <stdlib.h> /* randomize(), random() */


double urandom(){
    //RAND_MAX is a constant defined in the rand module
    return  (double)rand() / (double)RAND_MAX;
};


double random_sphere_coord(){
    return  2 * (urandom() - 0.5);
};
