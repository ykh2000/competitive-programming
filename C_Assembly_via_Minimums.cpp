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
    int n;cin>>n;
    int N = n*(n-1)/2;
    std::vector<int> b(N);
    std::vector<int>a;
    for (int i = 0; i < N; i++) {
        cin>>b[i];
    }
    //sort b in ascending order
    sort(b.begin(), b.end());
    int idx = 0;
    for (int i = 0; i < n-1; i++) {
        idx+=n-1-i;
        a.push_back(b[idx-1]);
    }
    a.push_back(1e9);

    for(int i:a){
        cout<< i << " ";
    }
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ;cin>>t;while(t--){
        solve();
    }

    return 0;
}