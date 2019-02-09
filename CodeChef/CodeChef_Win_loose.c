#include<stdio.h>

long long int gcd(long long int a, long long int b)  
{  
    // Everything divides 0  
    if (a == 0 || b == 0)  
        return 0;  
  
    // Base case     
    if (a == b)  
        return a;  
  
    // a is greater  
    if (a > b)  
        return gcd(a-b, b);  
    return gcd(a, b-a);  
}  
  
// Function to return LCM of two numbers  
long long int lcm(long long int a, long long int b)  
{  
    return (a*b)/gcd(a, b);  
} 
int main()
{
    long long int test,a,b,k,n,lcmres,ca,cb,res;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld %lld %lld %lld",&n,&a,&b,&k);
        lcmres=lcm(a,b);
        res=floor(n/lcmres);
        ca=floor(n/a);
        cb=floor(n/b);
        cb=(ca+cb)-(2*res);
        if(cb>=k)
        printf("Win\n");
        else
        printf("Lose\n");
        
    }
        


    
    return 0;
}