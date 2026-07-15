class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int evenSum =0;
        int oddSum = 0;
        int odd = 1;
        int even = 2;
        for(int i=0;i<n;i++){
            evenSum+=even;
            even+=2;
            oddSum+=odd;
            odd+=2;
        }
        return gcd(oddSum,evenSum);
    }
};