#include <stdio.h>
#include <string.h>
void Longest_increasing_sequence(int arr[], int n)
{
    int i = 0;
    int temp[n];
    memset(temp, 0, sizeof(temp));
    for (i = 0; i < n; i++)
        temp[i]++;
    for (i = 1; i < n; i++)
    {
        int j = 0;
        while (j < i)
        {
            if (arr[i] >= arr[j])
            {
                if (temp[j] + 1 == temp[i] + 1)
                {

                    temp[i]++;
                }
            }
            j++;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", temp[i]);
}
int main()
{
    int arr[] = {55, 12, 77, 14, 55};
    Longest_increasing_sequence(arr, 5);
    return 0;
}