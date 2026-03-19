class Solution {
public:
    long long divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }
        return dividend/divisor;
    }
};