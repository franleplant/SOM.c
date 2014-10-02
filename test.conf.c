#include "./lib/greatest/greatest.h"
#include "random/random.h"


extern SUITE(random_module);

/* Expand to all the definitions that need to be in
the test runner's main file. */
GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();      /* command-line arguments, initialization. */
    RUN_SUITE(random_module);   /* run a suite */
    GREATEST_MAIN_END();        /* display results */
}
