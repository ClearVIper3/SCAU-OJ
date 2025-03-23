#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct tree {
    int data;
    struct tree* left;
    struct tree* right;
} node;

int res = 0;
int dfs(node* root)
{
    if(root == NULL)
        return 0;
    int left = dfs(root->left);
    int right = dfs(root->right);
    res = max(res, left + right);
    return max(left, right) + 1;
}

int main() {
    int n;
    cin >> n;
    
    // 存储树的节点指针
    node* nod[n+1];
    for (int i = 0; i <= n; i++) {
        nod[i] = NULL;
    }
    
    // 构造树
    for (int i = 1; i <= n-1; i++) {
        int x, y;
        cin >> x >> y;
        
        if (nod[x] == NULL) 
        {
            nod[x] = new node;
            nod[x]->data = x;
            nod[x]->left = nod[x]->right = NULL;
        }
        
        if (nod[y] == NULL)
        {
            nod[y] = new node;
            nod[y]->data = y;
            nod[y]->left = nod[y]->right = NULL;
        }
        
        if (nod[x]->left == NULL)
            nod[x]->left = nod[y];
         else 
            nod[x]->right = nod[y];
    }

    // 计算树的深度，同时更新直径
    dfs(nod[1]);
    
    // 输出最大直径
    cout << res << endl;
    
    return 0;
}
