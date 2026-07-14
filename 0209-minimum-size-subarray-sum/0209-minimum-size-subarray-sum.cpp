class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 1;
        int right = nums.size();
        int ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (isValid(nums, target, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }

private:
    bool isValid(const vector<int>& nums, int target, int windowSize) {
        int currentSum = 0;
        
        for (int i = 0; i < windowSize; i++) {
            currentSum += nums[i];
        }
        if (currentSum >= target) return true;
        
        for (int i = windowSize; i < nums.size(); i++) {
            currentSum += nums[i];
            currentSum -= nums[i - windowSize];
            
            if (currentSum >= target) return true;
        }
        
        return false;
    }
};