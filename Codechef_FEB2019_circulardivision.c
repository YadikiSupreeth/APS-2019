#include<stdio.h>
int main()
{
    printf("%d",-1%4);
    long int i,a[102],d[102],test,n,max=0;
    scanf("%ld",&test);
    while(test--)
    {
        max=0;
        scanf("%ld",&n);
        for(i=0;i<n;i++)
            scanf("%ld",&a[i]);
        for(i=0;i<n;i++)
            scanf("%ld",&d[i]);
        
        for(i=0;i<n;i++)
        {
            if(d[i%n]>(a[(i-1)%n]+a[(i+1)%n]))
            {
                if(d[i%n]>max)
                max=d[i%n];
            }
        }
        if(max==0)
        printf("-1\n");
        else
        printf("%ld\n",max);
        
    }
    return 0;
}
