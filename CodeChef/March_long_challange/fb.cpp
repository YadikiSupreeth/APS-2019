#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    void countPathsUtil(int, int, bool[],
                        int &);

  public:
    Graph(int V);
    void addEdge(int u, int v);
    int countPaths(int s, int d);
};



Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int u, int v)
{

    // Add v to u’s list.
    adj[u].push_back(v);
}

void Graph::countPathsUtil(int u, int d, bool visited[],
                           int &pathCount)
{
    visited[u] = true;

    if (u == d)
        pathCount++;

    else
    {

        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                countPathsUtil(*i, d, visited,
                               pathCount);
    }

    visited[u] = false;
}
int Graph::countPaths(int s, int d)
{

    bool *visited = new bool[V];
    memset(visited, false, sizeof(visited));

    int pathCount = 0;
    countPathsUtil(s, d, visited, pathCount);
    return pathCount;
}

int main()
{

    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int arr[n + 1];
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        Graph g(n + 1);

        for (int i = 1; i <= n; i++)
        {
            if (arr[i] == 2)
            {

                if (i + 1 <= n)
                    g.addEdge(i, i + 1);
                if (i + 2 <= n)
                    g.addEdge(i, i + 2);
                if (i != 1)
                    g.addEdge(i, i - 1);
                if (i >= 3)
                    g.addEdge(i, i - 2);
              
            }
            else
            {
                  if (i != 1)
                    g.addEdge(i, i - 1);
                if (i != n)
                    g.addEdge(i, i + 1);
            }
        }
        int sa= 1, sum = 0;
        for (int i = 1; i <= n + 1; i++)
        {
            sum += g.countPaths(sa, i) % (1000000007);
        }
        printf("%d\n", sum % (1000000007));
    }

    return 0;
}
