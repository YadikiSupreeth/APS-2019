#include<string.h>
#include<stdio.h>
#include<math.h>
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        long long n,limit,flag=0;
        scanf("%lld %lld",&n,&limit);
        long long int a[n];
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);

        for(long long int i=0;i<n;i++)
        {
           double sum=0.0;
            double k=1.0;
            if(a[i]>limit)
                continue;
            for( int j=i;j<n;j++)
            {
                sum=sum+floor(a[j]/k);
                k++;
                if(sum>limit)
                    break;
            }
            if(sum<=limit)
                {
                    printf("%lld\n",i+1);
                    flag=1;
                    break;
                }
        }
        if(flag!=1)
            printf("%lld\n",n+1);
    }

}