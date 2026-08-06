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

bool isPrime(int x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i == 0) return 0;
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << 4 << " " << n - 4 << '\n';
    } else {
        cout << 9 << " " << n - 9 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}