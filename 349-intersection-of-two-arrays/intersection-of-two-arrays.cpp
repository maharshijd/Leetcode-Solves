class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num;
        int flag = 0;

        for (int i = 0; i < nums1.size(); i++) {
            flag = 0;
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    int k = nums1[i];
                    for (int m = 0; m < num.size(); m++) {
                        if (k == num[m]) {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) {
                        num.push_back(k);
                    }
                    break;
                }
            }
        }

        return num;
    }
};
