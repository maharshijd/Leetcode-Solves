class Solution {
public:
    string getPermutation(int n, int k) {
        string nums;
        for (int i = 1; i <= n; i++)
            nums += to_string(i);
        string ans;
        k--;
        vector<int> fact(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i;
        for (int i = n; i >= 1; i--) {
            int idx = k / fact[i - 1];
            k %= fact[i - 1];
            ans += nums[idx];
            nums.erase(nums.begin() + idx);
        }
        return ans;
    }
};