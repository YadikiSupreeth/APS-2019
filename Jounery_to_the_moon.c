#include <stdio.h>
int n = 0, level = 0, i, q, w;

int count;
void unionOf(int arr[n], int a, int b)
{
    int x, y;
    x = arr[b];
    y = arr[a];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == y)
        {
            arr[i] = x;
        }
    }
}
int main()
{
    scanf("%d %d", &n, &level);
    int arr[n];
    int x = level;
  
    for (i = 0; i < n; i++)
        arr[i] = i;
    for (i = 0; i < level; i++)
    {
        scanf("%d %d", &q, &w);
        unionOf(arr, q, w);
    }

    int hash[n];
    for (i = 0; i < n; i++)
    {
        hash[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        if (hash[arr[i]] == 0)
            count++;
        hash[arr[i]] += 1;
    }

   

    int com[count];
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(hash[i]!=0)
             com[j++]=hash[i];
    }

  
    int sum=0;
    for(i=0;i<count;i++)
    {
        for(j=i+1;j<count;j++)
        {
            sum+=com[i]*com[j];
        }
    }

    printf("%d",sum);

    return 0;
}