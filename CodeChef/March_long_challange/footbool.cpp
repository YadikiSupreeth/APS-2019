#include <iostream>
#include <numeric>
#include <queue>
using namespace std;
void showq(queue<vector<int>> gq)
{
    queue<vector<int>> g = gq;
    printf("queue: ");
    while (!g.empty())
    {
        vector<int> c = g.front();
        printf("%d %d   ", c[0], c[1]);
        g.pop();
    }
    cout << '\n';
}
/*
int main()
{
    queue<vector<int>> gquiz;
    vector<int> c;
    c.push_back(1);
    c.push_back(2);
    gquiz.push(c);
    vector<int> f;
    f.push_back(1);
    f.push_back(1);
    gquiz.push(f);

    cout << "The queue gquiz is : ";

    showq(gquiz);

    // cout << "\ngquiz.size() : " << gquiz.size();
    // cout << "\ngquiz.front() : " << gquiz.front();
    // cout << "\ngquiz.back() : " << gquiz.back();

    // cout << "\ngquiz.pop() : ";
    // gquiz.pop();
    // showq(gquiz);

    return 0;
}*/

int main()
{
    int test;
    scanf("%d", &test);
    while (test--)
    {
        int n, qsize = 0,final_count=0;
        scanf("%d", &n);
        int a[n+1], flag = 0;
        for (int i = 1; i < n; i++)
            scanf("%d", &a[i]);
        queue<vector<int>> qq;
        for (int i = 1; i <n; i++)
            printf("%d  ", a[i]);
        printf("\nn=%d\n",n);
        if (a[1] == 1)
        {
            vector<int> f;
            f.push_back(1);
            f.push_back(2);
            qq.push(f);
            qsize = 1;
        }
        else
        {
            vector<int> f;
            f.push_back(1);
            f.push_back(2);
            vector<int> x;
            x.push_back(1);
            x.push_back(3);
            qq.push(f);
            qq.push(x);
            qsize = 2;
        }
        showq(qq);
        while (qsize != 0)
        {
           vector<int>  see = qq.front();
            final_count++;
            qsize--;
            qq.pop();
            int x,y;
            x=see[0];y=see[1];
            if ( a[y] == 2)
            {
                if(x+2==y)
                {
                     vector<int> f;
                    f.push_back(y); f.push_back(x+1);
                    qq.push(f);
                    qsize+=1;
                    printf("2=1 ");
                }
                if (y + 2 <= n)
                {
                    vector<int> f; vector<int> x;
                    f.push_back(y); f.push_back(y+1);
                    x.push_back(y); x.push_back(y+2);
                    qq.push(f); qq.push(x);
                    qsize+=2;
                    printf("2=2 ");
                }
                else if(y+1<=n)
                {
                    vector<int> f;
                    f.push_back(y); f.push_back(y+1);
                    qq.push(f);
                    qsize+=1;
                    printf("2=3 ");
                }
                // if(x!=y+1)
                // {
                //     vector<int> f;
                //     f.push_back(y); f.push_back(x+1);
                //     qq.push(f);
                //     qsize+=1;
                // }
            }
            else
            {
                if(x+2==y && y+1<=n)
                {
                    vector<int> f; vector<int> x;
                    f.push_back(y); f.push_back(y-1);
                    x.push_back(y); x.push_back(y+1);
                    qq.push(f); qq.push(x);
                    qsize+=2;
                    printf("1=1 ");
                }
                else if(x+2==y)
                {
                    vector<int> f;
                    f.push_back(y); f.push_back(y-1);
                    qq.push(f);
                    qsize+=1;
                    printf("1=2 ");
                }
                else if(y+1<=n)
                {
                    vector<int> f;
                    f.push_back(y); f.push_back(y+1);
                    qq.push(f);
                    qsize+=1;
                    printf("1=3 ");
                }
               
            }
             printf("\n");
             showq(qq);
        }
        printf("final count %d\n",final_count+1);
    }
}