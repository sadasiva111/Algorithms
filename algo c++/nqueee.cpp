#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int board[1001][1001];
int n;
bool issafe(int row, int col)
{
    if (row >= n || col >= n)
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (board[row][j] == 1)
        {
            return false;
        }
    }
    int i = 0;
    for (int k = 0; k < n; k++)
    {
        for (int l = 0; l < n; l++)
        {
            if (((k + l) == (row + col)) || ((k - l) == (row - col)))
            {
                if (board[k][l] == 1)
                    return false;
            }
        }
    }
    return true;
}
bool solve(int col)
{
    if (col >= n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (issafe(i, col))
        {
            board[i][col] = 1;
            if (solve(col + 1))
            {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    bool flag = solve(0);
    if (flag)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
               cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
        return 0;
}