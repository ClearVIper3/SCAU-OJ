#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

typedef struct tree {
    struct tree* left;
    struct tree* right;
    int val;
} tree;

// 插入新节点到二叉搜索树
tree* insert(tree* root, int value) {
    if (root == nullptr) {
        tree* new_node = new tree;
        new_node->val = value;
        new_node->left = new_node->right = nullptr;
        return new_node;
    }

    // 根据值的大小决定插入左子树还是右子树
    if (value < root->val) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// 构建二叉搜索树
tree* build(const vector<int>& te) {
    tree* root = nullptr;

    for (int i = 0; i < te.size(); ++i) {
        root = insert(root, te[i]);  // 将每个元素插入到树中
    }

    return root;
}

// 翻转二叉树
void swp(tree* root) {
    if (!root) return;
    tree* temp = root->left;
    root->left = root->right;
    root->right = temp;
    swp(root->left);
    swp(root->right);
}

// 深度优先搜索（DFS）计算树的最大深度
int dfs(tree* root, int high, int res, int& count) {
    if (!root) return high;
    if (!root->left && !root->right) count++;  // 统计叶子节点
    int le = dfs(root->left, high + 1, res, count);
    int rg = dfs(root->right, high + 1, res, count);
    res = max(res, max(le, rg));
    return res;
}

// 广度优先搜索（BFS）遍历树
void bfs(tree* root) {
    queue<tree*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            tree* node = q.front();
            q.pop();
            cout << node->val << ' ';
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
}

// 前序遍历
void pre(tree* root) {
    if (root == NULL) return;
    cout << root->val << ' ';
    pre(root->left);
    pre(root->right);
}

// 中序遍历
void cur(tree* root) {
    if (root == NULL) return;
    cur(root->left);
    cout << root->val << ' ';
    cur(root->right);
}

// 后序遍历
void nex(tree* root) {
    if (root == NULL) return;
    nex(root->left);
    nex(root->right);
    cout << root->val << ' ';
}

// 非递归的中序遍历
void inorderIterative(tree* root) {
    stack<tree*> stk;
    tree* curr = root;

    while (curr != nullptr || !stk.empty()) {
        while (curr != nullptr) {
            stk.push(curr);
            curr = curr->left;
        }

        curr = stk.top();
        stk.pop();
        cout << curr->val << ' ';

        curr = curr->right;
    }
}

// 查找值是否存在于树中
bool find(tree* node, int val) {
    if (!node) return false;
    if (node->val == val) return true;
    return find(node->right, val) || find(node->left, val);
}

int main() {
    int n;
    cin >> n;
    vector<int> te(n);
    for (int i = 0; i < n; i++) cin >> te[i];
    
    int a, b;
    cin >> a >> b;

    int inse;
    cin >> inse;

    // 构建二叉搜索树
    tree* root = build(te);

    // 前序遍历
    pre(root);
    cout << endl;

    // 中序遍历
    cur(root);
    cout << endl;

    // 后序遍历
    nex(root);
    cout << endl;

    // 查找元素 a 和 b
    cout << (find(root, a) ? 1 : 0) << endl;
    cout << (find(root, b) ? 1 : 0) << endl;

    // 插入新节点
    insert(root, inse);

    // 插入后的前序遍历
    pre(root);
    cout << endl;

    // 插入后的中序遍历
    cur(root);
    cout << endl;

    // 插入后的后序遍历
    nex(root);
    cout << endl;

    // 非递归的中序遍历
    inorderIterative(root);
    cout << endl;

    // 广度优先遍历
    bfs(root);
    cout << endl;

    // 翻转二叉树并遍历
    swp(root);
    pre(root);
    cout << endl;

    cur(root);
    cout << endl;

    nex(root);
    cout << endl;

    //翻转回来并遍历
    swp(root);
    pre(root);
    cout << endl;

    cur(root);
    cout << endl;

    nex(root);
    cout << endl;

    // 统计树的深度和叶子节点
    int countleaf = 0;
    cout << dfs(root, 0, 0, countleaf) << endl;
    cout << countleaf << endl;

    return 0;
}
