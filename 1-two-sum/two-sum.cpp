class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> valid;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i] + nums[j] == target){
                    valid.push_back(i);
                    valid.push_back(j);
                    break;
                }
            }
        }
        return valid;
    }
};