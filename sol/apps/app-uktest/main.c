#include <stdio.h>

#include <uk/test.h>

int factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }

  return result;
}


UK_TESTCASE(factorial_testsuite, factorial_test_positive)
{
	UK_TEST_EXPECT_SNUM_EQ(factorial(2), 2);
}

uk_testsuite_register(factorial_testsuite, NULL);
