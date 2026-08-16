class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> mark(n, 0);
        vector<long long> ans;
        set<pair<int,int>> s;
        long long total = 0;
        for(int i = 0; i < n; i++) {
            s.insert({nums[i], i});
            total += nums[i];
        }
        for(int i = 0; i < queries.size(); i++) {
            int idx = queries[i][0];
            int k = queries[i][1];
            if(mark[idx] == 0) {
                mark[idx] = 1;
                total -= nums[idx];
                s.erase({nums[idx], idx});
            }
            for(int j = 0; j < k && !s.empty(); j++) {
                auto it = s.begin();
                int index = it->second;
                int value = it->first;
                mark[index] = 1;
                total -= value;
                s.erase(it);
            }
            ans.push_back(total);
        }
        return ans;
    }
};