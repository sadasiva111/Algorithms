#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[10001];
bool vis[10001];
int dis[10001];
void dijstar(int s)
{
    set<pair<int, int>> djs;
    dis[s] = 0;
    djs.insert(make_pair(0, s));
    while (djs.empty() == false)
    {
        pair<int, int> x = *(djs.begin());
        djs.erase(djs.begin());

        int u = x.second;
        for (auto it : adj[u])
        {
            int w = it.first;
            int v = it.second;
            if (dis[v] > dis[u] + w)
            {
                if (dis[v] != INT_MAX)
                {
                    djs.erase(djs.find(make_pair(dis[v], v)));
                }
                dis[v] = dis[u] + w;
                djs.insert(make_pair(dis[v], v));
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int u, v, w;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 0; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    dijstar(1);
    for (int i = 0; i < n; i++)
    {
        cout << dis[i];
    }

    return 0;
}