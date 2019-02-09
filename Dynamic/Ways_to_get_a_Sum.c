#include<stdio.h>
int ways_to_get_sum(int numbers[],int sum,int no_numbers)
{
    int i,l,r,j;
    int dp[1000];
    memset(dp,0,dp[0]*1000);

    for(i=0;i<=sum;i+=numbers[0])
        dp[i]=1;
    
    for(i=1;i<no_numbers;i++)
    {
        l=0;
        for(r=numbers[i];r<=sum;r++)
        {
            dp[r]+=dp[l];
            l++;
        }
    }
     for(i=0;i<=sum;i++)
        printf("%d ",dp[i]);
    return dp[sum];
}
int main()
{
    int n[]={1,2,5,10};

    printf("%d",ways_to_get_sum(n,12,4));
    return 0;
}