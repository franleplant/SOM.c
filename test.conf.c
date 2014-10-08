#include "./lib/greatest/greatest.h"
#include "random/random.h"


extern SUITE(random_module);
extern SUITE(point_module);
extern SUITE(neuron_module);



/* 
    Expand to all the definitions that need to be in
    the test runner's main file.
*/
GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    /* command-line arguments, initialization. */
    GREATEST_MAIN_BEGIN();        

    //Run suites
    RUN_SUITE(random_module);   
    RUN_SUITE(point_module);  
    RUN_SUITE(neuron_module);


    /* display results */
    GREATEST_MAIN_END(); 
}
