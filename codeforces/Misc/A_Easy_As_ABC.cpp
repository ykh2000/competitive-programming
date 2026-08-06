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
  vector<string> v(3);
  cin>>v[0]>>v[1]>>v[2];
  string ans = "ZZZ";
  int n = 3;
  for (int x1 = 0; x1 < n; x1++) {
    for (int y1 = 0; y1 < n; y1++)
    {
        for (int x2 = 0; x2 < n; x2++) {
            for (int y2 = 0; y2 < n; y2++) {
                for (int x3 = 0; x3 < n; x3++) {
                    for (int y3 = 0; y3< n; y3++)
                    {
                        if(x1 == x2  && y1 == y2)continue;
                        if(x1==x3 && y1 == y3)continue;
                        if(x2 == x3 && y2 == y3) continue;
                    
                    }
                    
                }
            }
        }
    }
    
  }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}