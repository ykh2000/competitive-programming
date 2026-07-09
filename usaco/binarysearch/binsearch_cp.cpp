#include <bits/stdc++.h>
using namespace std;


int lower(vector<int>&arr, int target){
    auto it = lower_bound(arr.begin(), arr.end(), target);
    return it-arr.begin();
}

int upper(vector<int>&arr, int target){
        auto it = upper_bound(arr.begin(), arr.end(), target);
        // change the iterator to int which is the return type.
        // I can't return an iterator
        return it-arr.begin();
}

bool check(vector<int> &arr, int target){
    auto it = lower_bound(arr.begin(), arr.end(), target);
    return (it!=arr.end() && *it == target);
}


int main()
{
    
    return 0;
}