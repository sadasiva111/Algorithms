#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[10001][10001];
bool vis[10001];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
void prims(int u, int p, int n)
{
    if (n == 0)
    {
        return;
    }

    vis[p] = true;
    for (int j = 0; j < n; j++)
    {
        if (arr[p][j] > 0)
        {
            if (vis[j] == false)
            {
                pq.push({arr[p][j], {p, j}});
            }
        }
    }
    pair<int, pair<int, int>> x = pq.top();
    pq.pop();
     if (vis[x.second.first] == true && vis[x.second.second] == true)
    {
        return;
    }

    cout << x.second.first << "->" << x.second.second << "----> " << x.first << endl;
    prims(x.second.first, x.second.second, n - 1);
}
int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    vis[0] = true;
    for (int j = 0; j < n; j++)
    {
        if (arr[0][j] > 0)
        {
            if (vis[j] == false)
            {
                pq.push({arr[0][j], {0, j}});
            }
        }
    }
    pair<int, pair<int, int>> x = pq.top();//weiht ,{u,v};
    pq.pop();

    cout << x.second.first << "->" << x.second.second << "----> " << x.first << endl;

    prims(x.second.first, x.second.second, n );
    return 0;,
}