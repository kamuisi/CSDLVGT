#include <iostream>
using namespace std;

struct node
{
    int key;
    node* left = NULL;
    node* right = NULL;
};

void Insert(node *root, int k)
{
    node* new_node = new node;
    node* point = new node;
    new_node->key = k;
    point = root;
    while(point != NULL)
    {
        if(k > point->key)
        {
            if(point->right == NULL)
            {
                point->right = new_node;
                return;
            }
            point = point->right;
        }
        else if(k < point->key)
        {
            if(point->left == NULL)
            {
                point->left = new_node;
                return;
            }
            point = point->left;
        }
        else return;
        
    }
}

bool Check(node *root)
{
    if(root == NULL)
    {
        return 1;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    if(root->left != NULL && root->right != NULL)
    {
        return Check(root->left) && Check(root->right);
    }
    return 0;
}

int main()
{
    node *root = new node;
    int n, k;
    cin >> n;
    cin >> root->key;
    for(int i = 1 ; i < n; i++)
    {
        cin >> k;
        Insert(root, k);
    }
    if(Check(root)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}