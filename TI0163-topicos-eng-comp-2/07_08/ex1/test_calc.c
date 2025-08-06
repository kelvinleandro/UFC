
#include "unity.h"
#include "calc.h"

void setUp(void) {
    // executado antes de cada teste
}

void tearDown(void) {
    // executado depois de cada teste
}

void test_add(void) {
    TEST_ASSERT_EQUAL(5, add(2, 3));
    TEST_ASSERT_EQUAL(0, add(-2, 2));
}

void test_subtract(void) {
    TEST_ASSERT_EQUAL(1, subtract(3, 2));
    TEST_ASSERT_EQUAL(-5, subtract(-3, 2));
}

void test_multiply(void) {
    TEST_ASSERT_EQUAL(6, multiply(2, 3));
    TEST_ASSERT_EQUAL(0, multiply(0, 100));
}

void test_divide(void) {
    TEST_ASSERT_EQUAL(2, divide(6, 3));
    TEST_ASSERT_EQUAL(0, divide(1, 0)); 
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_add);
    RUN_TEST(test_subtract);
    RUN_TEST(test_multiply);
    RUN_TEST(test_divide);

    return UNITY_END();
}
