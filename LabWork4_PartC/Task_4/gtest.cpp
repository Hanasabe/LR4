#include <gtest/gtest.h>

long long calc(long long n, long long *a)
{
    long long i, j, k, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum = 0;

    for (i = 0, j = 0, k = 0; j < n; i++, j++, k++) {
        sum1 += a[i * (n * n) + j * n + k];
    }

    for (i = n - 1, j = 0, k = 0; j < n; i--, j++, k++) {
        sum2 += a[i * (n * n) + j * n + k];
    }

    for (i = n - 1, j = n - 1, k = 0; k < n; i--, j--, k++) {
        sum3 += a[i * (n * n) + j * n + k];
    }

    for (i = 0, j = n - 1, k = 0; k < n; i++, j--, k++) {
        sum4 += a[i * (n * n) + j * n + k];
    }

    sum = (sum1 > sum2) ? sum1 : sum2;
    sum = (sum > sum3) ? sum : sum3;
    sum = (sum > sum4) ? sum : sum4;

    return sum;
}

TEST(Task4, Test4)
{
    long long n = 2, p;
    long long res = 98, a[n][n][n];
    p = calc(n, **a);

    // ASSERT_TRUE(eq);
    ASSERT_EQ(res, p);
}

int main()
{

    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}