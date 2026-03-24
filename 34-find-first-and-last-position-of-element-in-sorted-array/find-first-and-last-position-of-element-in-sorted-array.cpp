class Solution {
public:
    int lower(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
    
    int upper(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = lower(nums, target);
        int right = upper(nums, target) - 1;
        
        if (left <= right && right < nums.size() && nums[left] == target)
            return {left, right};
        
        return {-1, -1};
    }
};