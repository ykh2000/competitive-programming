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

/***
 * Empty Array.
 * Q queries. Each Query has one of two things:
 * Type 1: x (add this to the array)
 * 6 7
 * Query 1: 1 3
 * [] -> [3]
 * Query 2: 1 3
 * [3] -> [3,3]
 * 
 * Type 2: Print the occurence of the array.
 * Eg:- 
 * [1,6,3,3]
 * 
 * then: [2,1] ==> how many ones are there.
 * 
 * 
 */




void solve() {
    int n;cin>>n;
    int q;cin>>q;
    /***
     * 
    vector<int> name_of_vector(size, initial_value);
     * 
     */

     /**
      * This is called a frequency Array (Important)
      */

    vector<int> freq(n+1,0);
    while(q--){
        int type, x;
        cin>>type>>x;
        if(type == 1){
            freq[x]++;
        }
        else{
            cout<<freq[x]<<'\n';
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}