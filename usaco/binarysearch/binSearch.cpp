#include <bits/stdc++.h>
using namespace std;

// Check if the 1st element >= target

bool check_geq(const std:: vector<int>&arr, int mid, int target){
    return arr[mid]>=target;
}

int binary_search(const std::vector<int> &arr, int target){
    int lo = 0;int hi = arr.size()-1; int ans  = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(check_geq(arr,mid,target)){
            ans  = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    return ans;
}

/**
 * INT_MAX = 2,147,483,647 (Overflow on large values).
 * (lo+hi)/2 = lo/2 + hi/2;
 * 
 * lo + (hi-lo)/2;
 * lo + hi/2-lo/2
 * lo/2 + hi/2 (Same result).
 * 
 * Key Insight : hi-lo is always smaller than hi+lo, so it wont overflow 
 * with large numbers.
 * 
 */




int main()
{
    std::vector<int> arr = {5,6,3,4,22,66,7,1,12,35,6};
    sort(arr.begin(),arr.end());
    int target = 6;
    int idx = binary_search(arr,target);
    if(idx != -1){
        cout<< "Index: "<<idx<<", Value: "<<arr[idx];
    }else
    {
        cout<<"Target Not Found"<<endl;
    }
    
    
    return 0;
}