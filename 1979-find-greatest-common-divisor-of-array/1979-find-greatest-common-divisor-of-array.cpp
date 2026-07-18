class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min = nums[0];
        int n = nums.size();
        int max = nums[0];
        for(int i=0;i<n;i++){
            if(nums[i] > max) max = nums[i];
            if(nums[i] < min) min = nums[i];
        }
        return gcd(min,max);
    }
};