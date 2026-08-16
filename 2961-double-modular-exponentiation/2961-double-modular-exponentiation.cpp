class Solution {
public:
    long long power(long long a, long long b, long long mod) {
        long long result = 1;
        while (b > 0) {
            if (b % 2 == 1)
                result = (result * a) % mod;
            a = (a * a) % mod;
            b /= 2;
        }
        return result;
    }
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for (int i = 0; i < variables.size(); i++) {
            long long a = variables[i][0];
            long long b = variables[i][1];
            long long c = variables[i][2];
            long long m = variables[i][3];
            long long var1 = power(a, b, 10);
            var1 = power(var1, c, m);
            if (var1 == target)
                ans.push_back(i);
        }
        return ans;
    }
};
