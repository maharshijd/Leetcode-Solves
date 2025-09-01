class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> final_arr;
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j]) {
                final_arr.push_back(nums2[j]);
                j++;
            } else {
                final_arr.push_back(nums1[i]);
                i++;
            }
            
        }
        while(i<nums1.size()){
            final_arr.push_back(nums1[i]);
            i++;
        
        }
        while(j<nums2.size()){
            final_arr.push_back(nums2[j]);
            j++;
        
        }
        int mid = (final_arr.size()-1) /2 ;
        double median =0;

        if(final_arr.size()%2 == 0){
            median = final_arr[mid] + final_arr[mid+1];
            median/=2;
        }
        else median = final_arr[mid];
        
        return median;
    }

};