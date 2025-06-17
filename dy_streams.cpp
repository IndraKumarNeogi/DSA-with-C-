#include <bits/stdc++.h>
using namespace std;

int main() {
    int K;
    cin >> K;
    vector<pair<int, int>> intervals;

    for (int i = 0; i < K; ++i) {
        int L, R;
        cin >> L >> R;
        intervals.push_back({L, R});
    }

    sort(intervals.begin(), intervals.end());

    vector<pair<int, int>> merged;
    for (const auto& interval : intervals) {
        int start = interval.first;
        int end = interval.second;
        if (merged.empty() || merged.back().second < start) {
            merged.push_back({start, end});
        } else {
            merged.back().second = max(merged.back().second, end);
        }
    }

    long long total = 0;
    for (const auto& p : merged) {
        total += (p.second - p.first);
    }

    cout << total << endl;
    return 0;
}
