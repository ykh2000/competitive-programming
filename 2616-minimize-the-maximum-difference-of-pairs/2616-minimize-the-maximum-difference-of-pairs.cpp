class Solution {
public:
bool check(vector<int> &nums, int p, int mid){
    int cnt = 0;
    for(int i =0;i<nums.size()-1;i++){
        if(nums[i+1] -  nums[i] <= mid){
            cnt++;
            i++; // skip the element for next pair
        }
        if(cnt >= p){
            return true;
        }
    }
    return cnt >= p;

}

 int minimizeMax(vector<int>& nums, int p) {
        std::sort(nums.begin(), nums.end());
        //Search space => [0,max_possible_diff]
        int lo = 0, hi = nums.back()-nums.front();
        int result = hi;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            //Is is possible to find p pairs with a max diff of 'mid'
            if(check(nums,p,mid) == 1){
                result = mid; //mid is valid
                hi = mid-1; // left - try to find a smaller pair
            }else{
                lo = mid+1; //right, mid is too tight , we need somehting larger
            }
        }
        return result;
    }
};