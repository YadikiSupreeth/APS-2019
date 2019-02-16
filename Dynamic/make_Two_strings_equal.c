
/* U can insert delete or update to make string 1 equal to string2*/
int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int editDistDP(char str1[], char str2[], int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = j; 
            else if (j == 0)
                dp[i][j] = i; 
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1],      // Insert
                                   dp[i - 1][j],      // Remove
                                   dp[i - 1][j - 1]); // Replace
        }
    }

    return dp[m][n];
}

int main()
{
    // your code goes here
    char str1[] = "xyz";
    char str2 []= "c";

    printf("%d",editDistDP(str1, str2, 3, 1));

    return 0;
}
