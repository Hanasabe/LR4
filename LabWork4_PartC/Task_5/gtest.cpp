#include <gtest/gtest.h>

void calc(long long n, long long m, char a[3][3])
{
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            if (a[i][j] == '.')
                a[i][j] = '0';
        }
    }

    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            if (a[i][j] == '*')
            {
                for (int q = -1; q <= 1; q++)
                {
                    for (int w = -1; w <= 1; w++)
                    {
                        if (q == 0 && w == 0)
                            continue;
                        if (i + q >= 0 && i + q < n && j + w >= 0 && j + w < m)
                        {
                            if (a[i + q][j + w] != '*')
                            {
                                a[i + q][j + w] += 1;
                            }
                        }
                    }
                }
            }
        }
    }
}

TEST(Task5, Test5)
{
    long long n = 3, m = 3;

    char ans[3][3] = {
        {'*', '3', '*'},
        {'3', '*', '3'},
        {'*', '3', '*'}};

    char res[3][3] = {
        {'*', '.', '*'},
        {'.', '*', '.'},
        {'*', '.', '*'}};

    calc(n, m, res);

    bool eq = true;
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            if (ans[i][j] != res[i][j])
            {
                eq = false;
                break;
            }
        }
    }

    ASSERT_TRUE(eq);
}
