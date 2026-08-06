/**
 * Peak Element Finding on Leetcode
 * Bitonic Arrays - 
 * Array that are first increasing then decreasing - 
 * [1,5,9,11,9,2,1]
 * Increasing - [1,5,9,11]
 * Decreasing - [9,2,1]
 * Find the Index of the Peak (Highest Element)
 * mid = 11
 */

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>&arr, int mid){
    if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
        return 1;
    }
    else{
        return 0;
    }
}

int main(std::vector<int> &arr, int target)
{
    int lo = 0;int hi = arr.size()-1, ans = -1;
    while(lo<=hi){
        int mid = lo +(hi-lo)/2;
         if(check(arr,mid) == 1){
            ans = mid;
            hi = mid-1; //left search
         }
         else{
            lo = mid+1; //right search
         }

    }
    
    return 0;
}