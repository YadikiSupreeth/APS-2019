#include <string.h>
#include <stdio.h>
int n = 5;
int count = 1;
int val[6][2];
void dfs_without_rec(int graph[n + 1][n + 1], int visited[n + 1], int v)
{
    int stack[1000];
    int top = -1;
    stack[++top] = v;
    while (top >= 0)
    {
        int temp = stack[top];
        printf("%d ", temp);
        visited[stack[top]] = 1;
        top--;
        for (int i = 0; i <= n; i++)
        {
            if (visited[i] != 1 && graph[temp][i] == 1)
            {
                stack[++top] = i;
                visited[i] = 1;
                //break;
            }
        }
    }
}
void dfs_with_rec(int graph[n + 1][n + 1], int visited[n + 1], int v)
{
    visited[v] = 1;
    val[v][0] = count;
    printf("%d ", v);
    for (int i = 0; i <= n; i++)
    {
        if (visited[i] != 1 && graph[v][i] == 1)
        {
            count++;
            dfs_with_rec(graph, visited, i);
        }
    }
    count++;
    val[v][1] = count;
}
void main()
{

    //printf("enter the number of vertices\n");
    // scanf("%d",&n);
    // int graph[n+1][n+1];
    int graph[6][6] = {
        {0, 1, 1, 1, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0}};
    int visited[n + 1];
    memset(visited, 0, sizeof(visited));
    while (1)
    {
        int flag = 0;
        for (int i = 0; i <= n; i++)
        {
            if (visited[i] == 0)
            {
                flag = 1;
                dfs_with_rec(graph, visited, i);
                count++;
                break;
            }
        }
        if (flag == 0)
            break;
    }
    printf("\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d %d %d \n", i, val[i][0], val[i][1]);
    }
}