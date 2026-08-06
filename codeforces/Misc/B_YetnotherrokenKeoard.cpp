#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define const int INF = 1e9;
#define const int LLINF = 4e18;
#define const double EPS = 1e-9;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
const int N = 2e5+5;
using namespace std;
 
void solve() {
    std::string s;
    std::cin >> s;
    
    std::vector<int> u, l;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') {
            if (!u.empty()) {
                u.pop_back();
            }
        } else if (s[i] == 'b') {
            if (!l.empty()) {
                l.pop_back();
            }
        } else if (std::isupper(s[i])) {
            u.push_back(i);
        } else {
            l.push_back(i);
        }
    }
    
    int i = 0, j = 0;
    while (i < u.size() || j < l.size()) {
        if (i < u.size() && (j == l.size() || u[i] < l[j])) {
            std::cout << s[u[i++]];
        } else {
            std::cout << s[l[j++]];
        }
    }
    std::cout << "\n";
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}