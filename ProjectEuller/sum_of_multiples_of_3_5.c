#include<stdio.h>


  
// Function to return LCM of two numbers  
long long int lcm(long long int a, long long int b)  
{  
    return (a*b)/gcd(a, b);  
} 
int main()
{
    long long int test,n,sum=0;
    long long int k,l,z;
    scanf("%lld",&test);
    while(test--)
    {
        sum=0;
        scanf("%lld",&n);
         k=(n-1)/3;
         l=(n-1)/5;
         z=(n-1)/15;
        
        sum=3*((k*(k+1))/2);
        sum+=5*((l*(l+1))/2);
        sum-=15*((z*(z+1))/2);
        printf("%lld\n",sum);
        
    }
   
        


    
    return 0;
}