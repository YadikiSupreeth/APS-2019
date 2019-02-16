#include<stdio.h>
int kadanes(int arr[],int n)
{
    int max=0,tmax=0;
    for(int i=0;i<n;i++)
    {
        tmax=tmax+arr[i];
        if(tmax<0)
            tmax=0;
        if(max<tmax)
            max=tmax;
    }
    return max;
}
int Kadanes_indices(int arr[],int m)
{
    int max=0,tmax=0,start=0,end=0;
    for(int i=0;i<n;i++)
    {
        tmax=tmax+arr[i];
        if(tmax<0)
            {
                tmax=0;
                s=i+1;
            }
        if(max<tmax)
           { 
               max=tmax;
               end=i+1;
               start=s;
           }
    }
    return max;
}
int main()
{
    int arr[]={-2,-3,4,-1,-2,1,5,-3};
    printf("%d",kadanes(arr,8));
    return 1;
}