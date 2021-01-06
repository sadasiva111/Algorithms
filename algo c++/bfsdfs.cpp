#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[10001][10001];
int n;
bool vis[10001];
bool vis1[10001];
void dfs(int p)
{
    vis1[p] = true;
    cout << p << " ";
    for (int j = 0; j < n; j++)
    {
        if (arr[p][j] == 1)
        {
            if (vis[j] == false)
            {
                dfs(j);
            }
        }
    }
}
void bfs(int p)
{
    vis[p] = true;
    queue<int> q;
    cout << p << " ";
    q.push(p);
    while (q.empty() == false)
    {
        int x = q.front();
        q.pop();
        for (int j = 0; j < n; j++)
        {
            if (arr[x][j] == 1)
            {
                if (vis[j] == false)
                {
                    q.push(j);
                    cout << j << " ";
                    vis[j] = true;
                }
            }
        }
    }
}
int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    bfs(0);
    return 0;
}
