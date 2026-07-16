class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int max = nums[0];
        vector<int> prefixGCD;
        for(int i=0;i<n;i++){
            if(nums[i] > max) max = nums[i];
            prefixGCD.push_back(gcd(nums[i],max));
        }
        sort(prefixGCD.begin(),prefixGCD.end());
        long long sum = 0;
        for(int i=0;i<n/2;i++){
            sum+=gcd(prefixGCD[i],prefixGCD[n-i-1]);
        }
        return sum;
    }
};