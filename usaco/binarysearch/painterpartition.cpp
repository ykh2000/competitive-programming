/***
 * Binary Search on Answer - 
 * Similar Problems - 
 *  Book-Allocation
 *  Painter's Partition 
 *  Spilt Array Largest sum 
 * Given an Array - nums 
 * int k, spilt nums into k non-empty subarray such that the largest 
 * sum of any subarray is minimized.
 */

 /**
  * [min_possible, max_possible]
  * 
  */


#include <bits/stdc++.h>
using namespace std;
#define ll int long long 
int n,k;
int arr[100100]; // global scoped

int check(int mid){
    int last_painter_time_left = 0;
    int num_painter_spawned = 0;
    for(int i=0;i<n;i++){
        if(last_painter_time_left>=arr[i]){
            last_painter_time_left = arr[i];
        }
        else{
            num_painter_spawned++;
            last_painter_time_left = mid;
            if(last_painter_time_left>=arr[i]){
                last_painter_time_left-=arr[i];
            }
            else{
                return 0;
            }
        }
    }
}



signed main() { // by default returns - 32 bit Int.
    cin>>n>>k;
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    int lo = 0, hi = sum, ans = -1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(check(mid) == 1){
            ans=mid;
            hi = mid+1;
        }
        else{

        }
    }

}
