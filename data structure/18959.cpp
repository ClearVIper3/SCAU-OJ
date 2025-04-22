#include <iostream>
#include <deque>
#include <vector>
#include <string>
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;

    Node *root = nullptr;
    Creat(root, s, 0);
    if (!root) return 0;

    deque<Node*> dq;
    dq.push_back(root);
    bool rtl = false;

    while (!dq.empty()) {
        int sz = dq.size();
        vector<char> level;
        level.reserve(sz);

        for (int i = 0; i < sz; i++) {
            Node *cur = dq.front();
            dq.pop_front();
            level.push_back(cur->c);
            if (cur->left)  dq.push_back(cur->left);
            if (cur->right) dq.push_back(cur->right);
        }

        if (rtl) {
            reverse(level.begin(), level.end());
        }

        for (int i = 0; i < (int)level.size(); i++) {
            cout << level[i];
            if (i + 1 < (int)level.size()) cout << ' ';
        }
        cout << '\n';

        rtl = !rtl;
    }

    return 0;
}
