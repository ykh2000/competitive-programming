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

int gcd(int a,int b){
    int ans = 1;
    for (int i = 0; i < min(a,b); i++) {
        if(a%i == 0 && b%i == 0){
            ans = i;
        }
    }
    return ans;
}
void solve() {
    int a,b,k;cin>>a>>b>>k;
    int g = gcd(a,b);
    vi divisors;
    for (int i = 0; i < g; i++) {
        divisors.push_back(i);
    }
    sort(divisors.rbegin(), divisors.rend());
    cout<<divisors[k-1]<<'\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}