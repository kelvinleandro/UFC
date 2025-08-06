
#include "unity.h"
#include "str_utils.h"
#include <string.h>

void setUp(void) {}
void tearDown(void) {}

void test_reverse_string(void) {
    char str1[] = "hello";
    reverse_string(str1);
    TEST_ASSERT_EQUAL_STRING("olleh", str1);

    char str2[] = "";
    reverse_string(str2);
    TEST_ASSERT_EQUAL_STRING("", str2);

    reverse_string(NULL); // should not crash
}

void test_string_length(void) {
    TEST_ASSERT_EQUAL(5, string_length("hello"));
    TEST_ASSERT_EQUAL(0, string_length(""));
    TEST_ASSERT_EQUAL(0, string_length(NULL));
}

void test_count_char(void) {
    TEST_ASSERT_EQUAL(2, count_char("banana", 'a'));
    TEST_ASSERT_EQUAL(0, count_char("banana", 'z'));
    TEST_ASSERT_EQUAL(0, count_char(NULL, 'a'));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_reverse_string);
    RUN_TEST(test_string_length);
    RUN_TEST(test_count_char);

    return UNITY_END();
}
