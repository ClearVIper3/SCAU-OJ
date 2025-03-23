#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> res;

void dfs(string &s,int idx,int count,string path)
{
    if (count > 4) return;
    if (idx == s.size() && count == 4) {
        res.push_back(path);
        return;
    }

    for (int len = 1; len <= 3; len++) {
        if (idx + len > s.size()) break;
        
        string segment = s.substr(idx, len);
        int num = stoi(segment);

        if ((segment[0] == '0' && segment.size() > 1) || num > 255) continue;

        dfs(s, idx + len, count + 1, path + (path.empty() ? "" : ".") + segment);
    }
}

int main()
{
    string s; cin >> s;
    dfs(s,0,0,"");
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;
}
