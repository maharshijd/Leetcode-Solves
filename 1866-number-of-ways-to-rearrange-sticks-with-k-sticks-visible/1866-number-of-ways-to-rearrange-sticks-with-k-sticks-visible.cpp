class Solution {
public:
    int rearrangeSticks(int n, int k) {
        const long long MOD = 1e9 + 7;
        vector<long long> dp(k + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = min(i, k); j >= 1; j--) {
                dp[j] = (dp[j - 1] + (i - 1) * dp[j]) % MOD;
            }
        }
        return dp[k];
    }
};
