class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        double sum = 0;
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        int n = prices.size();
        int m = discounts.size();
        int k = min(m,n);
        for(int i=0;i<k;i++){
            int price_idx = n-i-1;
            int disc_idx = m-i-1;
            sum+= prices[price_idx] * (100.0-discounts[disc_idx])/100.0;
        }
        for(int i=0;i<n-k;i++) sum+=prices[i];
        return sum;
    }
};