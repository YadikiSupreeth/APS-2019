#include<iostream>
#include<stdio.h>
#include<math.h>
int main()
{
    long test;
    scanf("%ld",&test);
    while(test--)
    {
         long double sum=0.0;
        long long int n,d;
        scanf("%lld %lld",&n,&d);
        long long int q,m,i;
        q=d;
        i=0;
        while(n>0)
        {
            m=n%10;
            n=n/10;
            if(m<=q)
            {
                q=m;
                sum=sum+(m*pow(10,i));
            }
            else
            {
                sum=sum*10 ;
                sum=sum+d;
            }
            i++;

        }

        std::string str = std::to_string(sum);
        i=0;
        while(str[i]!='.')
        {
          printf("%c",str[i]);
          i++;
        }
        printf("\n");
        }
    return 0;
}
