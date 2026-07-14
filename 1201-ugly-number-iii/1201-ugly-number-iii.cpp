#define ll long long int

class Solution {

ll lcm(ll x,ll y){
    return (x*y)/ std::gcd(x,y);
}

public:
    int nthUglyNumber(int n, int a, int b, int c) {
        ll ab = lcm(a,b);
        ll bc = lcm(b,c);
        ll ac = lcm(a,c);
        ll abc = lcm(ab,c);
        ll lo = 1, hi = 2e9, ans = hi;
        while(lo<=hi){
            ll mid  = lo+(hi-lo)/2;
            ll count = mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ac + mid/abc;
            if(count >=n) {
                ans = mid;
                hi = mid-1; // left
            }
            else{
                lo = mid+1; //right
            }
        }
        return ans;
    }


};