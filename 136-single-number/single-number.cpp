class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ctr =0;
        int i=0;
        for(i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[i] == nums[j]) ctr++; 
            }
            if( ctr == 1){
                break;

            }
            ctr =0;
        }
        return nums[i];
    }
};