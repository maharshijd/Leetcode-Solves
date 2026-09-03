class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        for(int i =0;i<nums1.size();i++){
            if(nums1[i]%2 == 1) minOdd = min(minOdd,nums1[i]);
        }
        if(minOdd == INT_MAX) return true;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0 && nums1[i]<minOdd) return false;
        }
        return true;
    }
};