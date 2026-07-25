class Solution {
public:
    int maxProduct(int n) {
        vector<int> val;
        while(n!=0){
            int temp = n%10;
            val.push_back(temp);
            n/=10;
        }
        sort(val.begin(),val.end());
        int x = val.size();
        return val[x-1] * val[x-2];
    }
};