class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> final_arr;
        int i = 0, j = 0;

        // Merge the two arrays
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                final_arr.push_back(nums1[i++]);
            } else {
                final_arr.push_back(nums2[j++]);
            }
        }

        // Add remaining elements
        while (i < nums1.size()) {
            final_arr.push_back(nums1[i++]);
        }

        while (j < nums2.size()) {
            final_arr.push_back(nums2[j++]);
        }

        // Find the median
        int n = final_arr.size();
        if (n % 2 == 0) {
            return (final_arr[n/2 - 1] + final_arr[n/2]) / 2.0;
        } else {
            return final_arr[n/2];
        }
    }
};
