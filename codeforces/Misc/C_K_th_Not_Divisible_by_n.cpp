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

/**
 * Iteration mindset to mapping mindset
 * 
 * 
 */

void solve() {
    ll n,k;cin>>n>>k;
    // number of full blocks u skip
    ll blocks  = (k-1)/(n-1);
    /**
     * blocks * n => The Skipped Distance (blocks*n)
     */
    // numbers we have passed by skipping 
    // each block size is n, skipping total numbers = blocks*n;
    ll skipped_distance = blocks*n;
    /**
     * remainder is the valid number left to count in the current block 
     * Total number of valid number we already counted  =>
     * blocks*(n-1).
     * - subtracting k gives us - position of our target.
     * 
     */
    ll remainder = (k- blocks*(n-1));
    cout <<  skipped_distance + remainder <<endl;
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