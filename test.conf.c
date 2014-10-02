#include "./lib/greatest/greatest.h"



extern SUITE(example_suite);

/* Expand to all the definitions that need to be in
the test runner's main file. */
GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();      /* command-line arguments, initialization. */
    RUN_SUITE(example_suite);   /* run a suite */
    GREATEST_MAIN_END();        /* display results */
}
