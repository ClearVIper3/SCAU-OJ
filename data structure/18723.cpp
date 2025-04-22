#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef struct t{
    char val;
    struct t* left = nullptr,* right = nullptr;
}trr;

trr* dfs(string s)
{
    if(s.size() == 1)
    {
        if(s[0] == '0')
        {
            trr* node = new trr;
            node -> val = 'B';
            return node;
        }
        trr * node = new trr;
        node -> val = 'I';
        return node;
    }

    trr* node = new trr;

    node -> left = dfs(s.substr(0,s.size() / 2));
    node -> right = dfs(s.substr(s.size() / 2));

    if(node -> left -> val == 'I' && node -> right -> val == 'I') node -> val = 'I';
    else if(node -> left -> val == 'B' && node -> right -> val == 'B') node -> val = 'B';
    else node -> val = 'F';
    return node;
}

void n_dfs(trr* root)
{
    if(!root) return;
    n_dfs(root -> left);
    n_dfs(root -> right);
    cout << root -> val;
}


int main()
{
    int n;
    cin >> n;
    int sz = pow(2,n);

    string s;
    cin >> s;

    n_dfs(dfs(s));
    return 0;
}
