#include<stdio.h>
#include<string.h>
int get_n_c_k(int i,int j)
{
    if(i==0 || j==0 || i==j)
    return 1;
    else
    {
       return ( get_n_c_k(i-1,j) + get_n_c_k(i-1,j-1));
    }

}
int min(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;
}
int pascal_1D(int m,int k)
{
    int c[k+1];
    memset(c,0,sizeof(c));
    c[0]=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=min(i,k);j>0;j--)
        {
                c[j]=c[j]+c[j-1];
        }
    }
    return c[k];
}
void pascal(int m,int k)
{
    int arr[100][100],limit;
    for(int i=0;i<m+1;i++)
    {
        if(i>k+1)
            limit=k+1;
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
        if(i>k+1)
            limit=k+1;
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
    pascal(n,k);  // 2D array
    printf("%d ", pascal_1D(10,10));  //1D array
    return 1;
}