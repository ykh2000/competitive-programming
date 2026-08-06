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
    int n,m;cin>>n>>m;
    vector<pair<int,int>> p;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin>>grid[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(grid[i][j] == '*'){
                p.push_back({i,j});
            }
        }
    }
    int r1 = p[0].first, c1 = p[0].second;
    int r2 = p[1].first, c2 = p[1].second;
    int r3 = p[2].first, c3 = p[2].second;
    int r4,c4;

    if(r1 == r2) r4 = r3;
    else if(r1==r3) r4 = r2;
    else r4 = r1;

    if (c1 == c2) c4 == c3;
    else if (c1 == c3) c4 = c2;
    else c4 = c1;
    cout << r4+1 << " " << c4 + 1 <<'\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}