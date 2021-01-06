#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data; //frequency
    char ch;  //charcter
    struct Node *left;
    struct Node *right;
};

int bits;
void inorder(struct Node *root, int h)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {

        cout << root->ch << h << endl;
    }

    inorder(root->left, h + 1);
    inorder(root->right, h + 1);
}
int main()
{

    priority_queue< pair<int, struct Node *>, vector<pair<int, struct Node *>>, greater<pair<int, struct Node *>>> pq;
    int n;
    cin >> n;
    int x;
    char y;
    while (n--)
    {
        cin >> y;
        cin >> x;
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

        temp->data = x;
        temp->ch = y;
        temp->left = NULL;
        temp->right = NULL;
        pq.push({x, temp}); //{ jhgbz  ,  3}
    }

    while (pq.size() != 1)
    {
        struct Node *temp1;
        pair<int, struct Node *> v = pq.top();

        temp1 = v.second;
        int a = v.first;

        pq.pop();

        struct Node *temp2;
        temp2 = pq.top().second;
        int b = pq.top().first;

        pq.pop();

        int z = a + b;

        struct Node *temp3 = (struct Node *)malloc(sizeof(struct Node));
        temp3->data = z;
        temp3->ch = '$';
        temp3->left = temp1;
        temp3->right = temp2;
        pq.push({z, temp3});
    }

    // cout << pq.top().first << endl;
    inorder(pq.top().second, 0);

    return 0;
}