#include "unity.h"
#include "deti.h"

void setUp(void) {}
void tearDown(void) {}

void test_isPrime(void)
{
  TEST_ASSERT_EQUAL(0, isPrime(-5));
  TEST_ASSERT_EQUAL(0, isPrime(0));
  TEST_ASSERT_EQUAL(0, isPrime(1));
  TEST_ASSERT_EQUAL(1, isPrime(2));
  TEST_ASSERT_EQUAL(1, isPrime(3));
  TEST_ASSERT_EQUAL(0, isPrime(4));
  TEST_ASSERT_EQUAL(1, isPrime(17));
  TEST_ASSERT_EQUAL(1, isPrime(31));
}

void test_sumPositiveNumbers(void)
{
  int arr1[] = {1, -2, 3, 4, -5};
  int arr2[] = {-1, -2, -3};
  int arr3[] = {10, 20, 30};

  TEST_ASSERT_EQUAL(8, sumPositiveNumbers(arr1, 5));
  TEST_ASSERT_EQUAL(0, sumPositiveNumbers(arr2, 3));
  TEST_ASSERT_EQUAL(60, sumPositiveNumbers(arr3, 3));
}

void test_mostCommonChar(void)
{
  TEST_ASSERT_EQUAL('a', mostCommonChar("banana"));
  TEST_ASSERT_EQUAL('l', mostCommonChar("hello"));
  TEST_ASSERT_EQUAL('a', mostCommonChar("abab"));
  TEST_ASSERT_EQUAL('o', mostCommonChar("ooooo"));
  TEST_ASSERT_EQUAL('\0', mostCommonChar(""));
  TEST_ASSERT_EQUAL('\0', mostCommonChar(NULL));
}

int main(void)
{
  UNITY_BEGIN();

  RUN_TEST(test_isPrime);
  RUN_TEST(test_sumPositiveNumbers);
  RUN_TEST(test_mostCommonChar);

  return UNITY_END();
}
