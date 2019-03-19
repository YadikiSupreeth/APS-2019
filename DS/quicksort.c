#include <stdio.h>
int N;
void quickSort(int arr[N], int size, int l, int r)
{
    if(l>r)
        return;
    int pivot = arr[l];
    int i = l+1, j = r;
    do
    {
        while (arr[i] < pivot)
        {
            i++;
        }

       while (arr[j] > pivot )
       {
           j--;
       }
        if(i<j)
        {int temp = arr[i];
       // printf("%d %d %d\n",temp,i,j);
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;}
        for(int i=0;i<N;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    }while(j>i);

    int temp = arr[j];
    arr[j] = pivot;
    arr[l] = temp;
  
    quickSort(arr, j - l, l, j - 1);
     quickSort(arr, r - j, j + 1, r);

}
void main()
{
    int arr[] = {10, 1, 20, 3, 4, 5, 100, 0, 99};
    N = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n",N);
    quickSort(arr, N, 0, N-1);
    for(int i=0;i<N;i++)
    {
        printf("%d ",arr[i]);
    }
}