
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> ppi;
vector<int> mergeKArrays(vector<vector<int>> arr)
{
    vector<int> p;

    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;

    for (int i = 0; i < arr.size(); i++)
        pq.push({arr[i][0], {i, 0}});

    while (pq.empty() == false)
    {
        ppi curr = pq.top();
        pq.pop();

        int i = curr.second.first;
        int j = curr.second.second;

        p.push_back(i + 1);

        if (j + 1 < arr[i].size())
            pq.push({arr[i][j + 1], {i, j + 1}});
    }

    return p;
}

int main()
{

    vector<vector<int>> stringss;
    int n;
    
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        vector<int> n;
        std::copy(s.begin(),s.end(),std::back_inserter(n));
        stringss.push_back(n);
    }

    vector<int> output = mergeKArrays(stringss);

    cout << "Merged array is " << endl;
    for (auto x : output)
        cout << x << " ";

    return 0;
}
