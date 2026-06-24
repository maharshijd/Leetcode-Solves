class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> seen(nums.size(), 0);
        vector<int> ans(2);

        for (int i = 0; i < nums.size(); i++) {
            int idx = nums[i] - 1;

            if (seen[idx] != 0) {
                ans[0] = nums[i];
            }

            seen[idx] = nums[i];
        }

        for (int i = 0; i < seen.size(); i++) {
            if (seen[i] == 0) {
                ans[1] = i + 1;
                break;
            }
        }

        return ans;
    }
};