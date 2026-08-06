#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for (char c : s)
        freq[c - 'a']++;

    int cnt = 0;
    for (int x : freq)
        cnt += min(x, 2);

    cout << cnt / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}