#include <stdlib.h>
#include <stdio.h>
int n, i;
typedef struct result{
    int a;
    int b;

}res;
void unionOf(int arr[n], int a, int b)
{
    int x, y;
    x = arr[b];
    y = arr[a];
    for (i = 0; i < n; i++)
    {
        if (arr[i] == y)
        {
            arr[i] = x;
        }
    }
}
res find(int arr[n],int a,int b)
{
    while(arr[b]!=b)
        b=arr[b];
    while(arr[a]!=a)
        a=arr[a];
    res r;
    r.a=a;
    r.b=b;
    return r;

}
void main()
{
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
        arr[i] = i;
    // unionOf(arr, 2, 1);
    // unionOf(arr, 4, 3);
    // unionOf(arr, 8, 4);
    // unionOf(arr, 9, 3);
    // unionOf(arr, 6, 5);
    // for (i = 0; i < n; i++)
    //     printf("%d ", arr[i]);
    // res r=find(arr,8,9);
    // printf("\n%d %d\n",r.a,r.b);
     unionOf(arr, 0, 1);
    unionOf(arr, 2, 3);
     unionOf(arr, 0, 4);
     for (i = 0; i < n; i++)
     printf("%d ", arr[i]);


}