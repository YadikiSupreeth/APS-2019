#include <stdio.h>
#include <string.h>

int min2(int x, int y)
{
    return (x < y) ? x : y;
}
int min(int a, int b, int c)
{
    return min2(a, min2(b, c));
}
int edit_distance(char s1[], char s2[], int l1, int l2)
{
    int dp[l1 + 1][l2 + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }
    return dp[l1][l2];
}
int main()
{
    printf("%d", edit_distance("day", "day", 3, 3));
    return 0;
}