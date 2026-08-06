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
 * 1. Find the closest tower to each city
 *  We will Find the distance  - 
 * Cities - -2,2,4 (co-ordinates) 
 * Towers - -3,0   (co-ordinates)
 * only X coordinates.
 * 
 * City 1: (-2) 
 * Tower at -3 : |-2-(-3)| = 1
 * Tower at 0 :  |-2-0|= 2
 * Closest tower distance = 1
 * 
 * Same for the City at 2 and 4.
 */

bool check(vector<ll>&c, vector<ll>&t, ll r){
    //check if all the cities can be covered with radius r
    int j = 0;
    for (int i = 0; i < c.size(); i++) {
        while(j<t.size() && t[j] < c[i]-r){
            j++;
        }

        if(j>=t.size() || t[j] > c[i]+r){
            return false;
        }
    }
    return true;
}

void solve() {
int n,m;
cin>>n>>m;
vector<ll> c(n),t(m);
for (int i = 0; i < n; i++) {
    cin>>c[i];
}
for (int i = 0; i < m; i++) {
    cin>>t[i];
}

ll lo = 0, hi = 2e9, ans = hi;
while(lo<=hi){
    ll mid = lo+(hi-lo)/2;
    if(check(c,t,mid)){
        ans = mid;
        hi = mid-1; //left
    }
    else
    {
        lo = mid+1; //right
    }
    
}
    cout<< ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}