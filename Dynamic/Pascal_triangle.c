#include<stdio.h>
#include<string.h>
void pascal(int m,int k)
{
    int arr[100][100],limit;
    for(int i=0;i<m+1;i++)
    {
        if(i>k)
            limit=k;
        else
            limit=i;
        for(int j=0;j<=limit;j++)
        {
            if(i==j)
                arr[i][j]=1;
            else if(i==0 || j==0)
                arr[i][j]=1;
            else
            {
                arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
            }
        }
    }
    for(int i=0;i<m+1;i++)
    {
        if(i>k)
            limit=k;
        else
            limit=i;
        for(int j=0;j<=limit;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }


}
int main()
{
    int n= 10;
    int k=5;
    pascal(n,k);
    return 1;
}