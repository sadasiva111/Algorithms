#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int kanpsack(int wt[], int pf[], int w, int n)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    
    if (w >= wt[n - 1])
    {
        
        return max(kanpsack(wt, pf, w, n - 1),
                   kanpsack(wt, pf, w - wt[n - 1], n - 1) + pf[n - 1]);
    }
    else
    {
        //exclude
        return kanpsack(wt, pf, w, n - 1);
    }
}
int main()
{
    int n;     
    cin >> n;
    int pf[n];
    int wt[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pf[i];
    }
    int w;
    cin >> w;
    int max = kanpsack(wt, pf, w, n);
    cout<<"max profit is :"<<max;

    return 0;
}