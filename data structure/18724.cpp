#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct Node
{
    char data;
    Node *left;
    Node *right;
}Node;

Node* buildTree(string pre, string in)
{
    if(pre.size() == 0)
        return NULL;
    Node *root = new Node;
    root->data = pre[0];
    int pos = in.find(pre[0]);
    root -> left = buildTree(pre.substr(1, pos), in.substr(0, pos));
    root -> right = buildTree(pre.substr(pos+1), in.substr(pos+1));
    return root;
}

void nex(Node *root)
{
    if(root == NULL)
        return;
    nex(root->left);
    nex(root->right);
    cout << root->data;
}

int main()
{
    string pre,in;
    cin >> pre;
    cin >> in;
    Node* root = buildTree(pre, in);
    nex(root);
    return 0;
}
