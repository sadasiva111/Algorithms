#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {

            cout << "found at" << i;
            return 0;
        }
    }

    cout << "not found";
    return 0;
}