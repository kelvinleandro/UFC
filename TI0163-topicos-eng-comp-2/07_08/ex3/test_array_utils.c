
#include "unity.h"
#include "array_utils.h"

void setUp(void) {}
void tearDown(void) {}

void test_sum_array(void) {
    int arr1[] = {1, 2, 3, 4};
    TEST_ASSERT_EQUAL(10, sum_array(arr1, 4));
    TEST_ASSERT_EQUAL(0, sum_array(NULL, 4));
    TEST_ASSERT_EQUAL(0, sum_array(arr1, 0));
}

void test_find_max(void) {
    int arr1[] = {1, 3, 2, 5, 4};
    TEST_ASSERT_EQUAL(5, find_max(arr1, 5));
    TEST_ASSERT_EQUAL(0, find_max(NULL, 5));
    TEST_ASSERT_EQUAL(0, find_max(arr1, 0));
}

void test_find_min(void) {
    int arr1[] = {3, 1, 4, 2};
    TEST_ASSERT_EQUAL(1, find_min(arr1, 4));
    TEST_ASSERT_EQUAL(0, find_min(NULL, 4));
    TEST_ASSERT_EQUAL(0, find_min(arr1, 0));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_sum_array);
    RUN_TEST(test_find_max);
    RUN_TEST(test_find_min);

    return UNITY_END();
}
