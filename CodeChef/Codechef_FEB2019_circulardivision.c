#include<stdio.h>
int main()
{
   long int test=0;
    scanf("%ld",&test);
    while(test--)
    {
         long int i,a[102],d[102],n,max=0,l,r;
        scanf("%ld",&n);
       // printf("n==%ld\n",n);
        for(i=0;i<n;i++)
            scanf("%ld",&a[i]);
        for(i=0;i<n;i++)
            scanf("%ld",&d[i]);
        
        for(i=0;i<n;i++)
        {long int ab=d[i];
            l=(i-1)%n;
            if(l<0)
                l=n-1;
            r=(i+1)%n;
            
        
        long int ca=a[l]+a[r];
       // printf("%ld %ld\n",ab,ca);
            if(ab>ca)
            {
                if(ab>max)
                max=ab;
              
            }
        }
       // printf("max=%ld\n",max);
        if(max!=0)
        printf("%ld\n",max);
        else
        printf("-1\n");
        
    }
    return 0;
}

