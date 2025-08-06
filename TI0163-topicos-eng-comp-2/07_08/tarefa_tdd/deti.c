#include <stddef.h>
#include "deti.h"

int isPrime(int n)
{
  if (n <= 1)
    return 0;
  if (n == 2)
    return 1;
  if (n % 2 == 0)
    return 0;

  for (int i = 3; i * i <= n; i += 2)
  {
    if (n % i == 0)
      return 0;
  }

  return 1;
}

int sumPositiveNumbers(int arr[], int size)
{
  int sum = 0;
  for (int i = 0; i < size; i++)
  {
    if (arr[i] > 0)
    {
      sum += arr[i];
    }
  }
  return sum;
}

char mostCommonChar(char *str)
{
  if (str == NULL || *str == '\0')
    return '\0';

  int freq[256] = {0};
  char *ptr = str;

  // Count frequency of each character
  while (*ptr != '\0')
  {
    freq[(unsigned char)*ptr]++;
    ptr++;
  }

  int maxFreq = 0;
  char mostCommon = '\0';

  for (ptr = str; *ptr != '\0'; ptr++)
  {
    if (freq[(unsigned char)*ptr] > maxFreq)
    {
      maxFreq = freq[(unsigned char)*ptr];
      mostCommon = *ptr;
    }
  }

  return mostCommon;
}
