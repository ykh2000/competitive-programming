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
    ll a,b,c;cin>>a>>b>>c;
    ll tents = a;
    ll ans = a+b/3;
    ll rem = b%3;
    if(rem == 1){
        if(c<2){
            cout<< -1 <<"\n";
            return;
        }
        ans++;
        c-=2;
    }
    else if(rem == 2){
        if(c<1){
            cout<<-1<<"\n";
            return;
        }
        ans++;
        c-=1;
    }
    ans+=(c+2)/3;
    cout<< ans <<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;while(t--){
        solve();
    }

    return 0;
}