class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            int temp = nums1[i];
            int j =0;
            while(nums2[j]!=temp){
                j++;
            }
            for(;j<nums2.size();j++){
                if(nums2[j] > temp) {
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }
};