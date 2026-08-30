class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        if(n==2) return 2;
        int minIDX = 0; int minVal = nums[0];
        int maxIDX = 0; int maxVal = nums[0];
        for(int i =0;i<n;i++){
            if(minVal > nums[i]){
                minVal = nums[i];
                minIDX = i;
            }
            if(maxVal < nums[i]){
                maxVal = nums[i];
                maxIDX = i;
            }
        }
        int left = min(minIDX,maxIDX);
        int right = max(minIDX,maxIDX);
        int deletions = min({right+1,n-left,left+1+n-right});
        return deletions;
    }
};