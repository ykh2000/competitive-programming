#include <bits/stdc++.h>
using namespace std;
//global variables
bool check_geq(const std:: vector<int>&arr, int mid, int target){
    if(arr[mid]>arr[0]){
        return 1;
    }
    else return 0;
    //return arr[mid]<arr[0]; //just changed this
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











