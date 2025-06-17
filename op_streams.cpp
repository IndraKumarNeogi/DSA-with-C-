#include <bits/stdc++.h>
using namespace std;

int main() {
    int K;
    cin >> K;
    map<int, int> merged;
    for (int i = 0; i < K; ++i) {
        int L, R;
        cin >> L >> R;
        auto it = merged.lower_bound(L);
        if (it != merged.begin()) {
            --it;
            if (it->second < L) ++it;
        }

        while (it != merged.end() && it->first <= R) {
            L = min(L, it->first);
            R = max(R, it->second);
            it = merged.erase(it);
        }
        merged[L] = R;
    }

    long long total = 0;
    for (auto it = merged.begin(); it != merged.end(); ++it) {
        total += (it->second - it->first);
    }
    cout << total << endl;
    return 0;
}
