class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> range(n);
        for(int i=0;i<n;i++){
            int temp = nums[i];
            int max=temp%10,min=temp%10;
            temp/=10;
            while(temp!=0){
                int dig = temp%10;
                if(dig > max) max = dig;
                if(dig < min) min = dig;
                temp/=10;
            }
            range[i] = max-min;
        }
        int sum = 0;
        int ref = *max_element(range.begin(),range.end());
        for(int i=0;i<n;i++){
            if(range[i] == ref) sum+=nums[i];
        }
        return sum;
    }
};