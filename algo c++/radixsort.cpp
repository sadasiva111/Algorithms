#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void bubblesort(int digts[], int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (digts[j] > digts[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                int temp1 = digts[j];
                digts[j] = digts[j + 1];
                digts[j + 1] = temp1;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    int nodgs = 0;
    while (max > 0)
    {
        max = max / 10;
        nodgs++;
    }
    int count = 0;
    while (nodgs--)
    {
        count++;
        int digts[n];
        for (int i = 0; i < n; i++)
        {
            int y = arr[i];
            int count1 = count;
            int rem;
            while (y > 0 && count1 > 0)
            {
                rem = y % 10;
                y = y / 10;
                count1--;
            }
            if(count1==0){
                digts[i] = rem;
            }
            else{
               digts[i] = 0;
 
            }

            
        }
        bubblesort(digts, arr, n);//any stamdard sort
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}