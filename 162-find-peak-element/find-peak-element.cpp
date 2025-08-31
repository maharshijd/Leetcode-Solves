class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int idx=0;
        int max= nums[0];
        for(int i=0;i<nums.size();i++){
            if(max < nums[i]){
                idx=i;
                max = nums[i];
            }
        }
        return idx;
    }
};