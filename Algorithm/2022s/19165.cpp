#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int day_counts = new int [20];  // 使用哈希表记录每一天的检测人数

    for (int i = 0; i < n; i++) {
        long long start_day;
        cin >> start_day;

        day_counts[start_day]++;
        day_counts[start_day + 2]++;
        day_counts[start_day + 6]++;
        day_counts[start_day + 10]++;
    }

    int result = 0;
    for (const auto &entry : std::end) {
        if (entry.second >= k) {
            result++;
        }
    }

    cout << result << endl;
    return 0;
}
