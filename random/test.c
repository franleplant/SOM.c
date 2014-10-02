 #include "random.h"
 #include "../lib/greatest/greatest.h"


SUITE(random_module);


TEST test_random() {
    double result = urandom();
    
    ASSERTm("it should return a random number greater than 0", result > 0); 
    ASSERTm("it should return a random number smaller than 1", result < 1); 

    PASS();
}


TEST test_random_sphere_coord() {
    double result =  random_sphere_coord();
    
    ASSERTm("it should return a random number greater than -1", result > -1); 
    ASSERTm("it should return a random number smaller than 1", result < 1); 

    PASS();
}


SUITE(random_module) {
    RUN_TEST(test_random);
    RUN_TEST(test_random_sphere_coord);
}
