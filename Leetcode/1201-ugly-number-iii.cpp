#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution {
    ll _gcd(ll a, ll b) {
        return b == 0 ? a : _gcd(b, a % b);
    }

    ll lcm(ll x, ll y) {
        return (x * y) / _gcd(x, y);
    }

public:
    int nthUglyNumber(int n, int a, int b, int c) {
        ll ab = lcm(a, b);
        ll bc = lcm(b, c);
        ll ac = lcm(a, c);
        ll abc = lcm(ab, c);

        ll lo = 1, hi = 2e9, ans = hi;
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            ll count = mid / a + mid / b + mid / c
                     - mid / ab - mid / bc - mid / ac
                     + mid / abc;

            if (count >= n) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << sol.nthUglyNumber(n, a, b, c) << '\n';

    return 0;
}