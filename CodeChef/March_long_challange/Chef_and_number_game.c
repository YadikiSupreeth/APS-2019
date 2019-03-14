#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,d;
        int pos=0,neg=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&d);
            if(d<0)
                neg++;
            else
                pos++;
        }
        if(neg==0)
            printf("%d %d\n",pos,pos);
        else if(pos==0)
            printf("%d %d\n",neg,neg);
        else if(pos<neg)
            printf("%d %d\n",neg,pos);
        else
        {
            printf("%d %d\n",pos,neg);
        }
    }
    return 0;
}