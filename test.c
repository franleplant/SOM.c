 #include "./lib/greatest/greatest.h"

SUITE(example_suite);


TEST example() {
    ASSERT_EQ(1, 1); 
    PASS();
}

SUITE(example_suite) {
    RUN_TEST(example);
}
