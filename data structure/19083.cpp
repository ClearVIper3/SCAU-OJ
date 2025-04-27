#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    char c;
    Node *left, *right;
    Node(char ch): c(ch), left(nullptr), right(nullptr) {}
};

// 从顺序存储的完全二叉树（字符串 s）按下标 i 递归建指针树
void Creat(Node *&root, const string &s, int i) {
    if (i >= (int)s.size() || s[i] == '#') {
        root = nullptr;
        return;
    }
    root = new Node(s[i]);
    Creat(root->left,  s, 2*i + 1);
    Creat(root->right, s, 2*i + 2);
}

int res = 0;
int deep(Node* root)
{
    if(!root)
        return 0;

    int left = deep(root -> left);
    int right = deep(root -> right);

    res = max(res,left + right);
    return max(left,right) + 1;
}

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;

    Node* root = nullptr;
    Creat(root,str,0);

    deep(root);

    cout << res << endl;

    return 0;
}
