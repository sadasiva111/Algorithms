#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (min > arr[i])
        {
            min = arr[i];
        }
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    int r = (max - min);
    int count[r + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i] - min]++;
    }
    for (int i = 0; i < r + 1; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            cout << i+min << " ";
        }
    }
    return 0;
}