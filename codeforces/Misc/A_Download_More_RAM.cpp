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
    int n,k;cin>>n>>k;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i].first;
    }
   for (int i = 0; i < n; i++) {
        cin>>v[i].second;
   }

   sort(v.begin(),v.end());
   for (int i = 0; i < n; i++) {
    if(v[i].first<=k){
        k+=v[i].second;
    }
   }
   cout<<k<<'\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}