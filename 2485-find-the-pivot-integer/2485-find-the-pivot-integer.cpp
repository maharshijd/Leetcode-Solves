class Solution {
public:
    int pivotInteger(int n) {
        for(int i=1;i<=n;i++){
            int sum1 = i*(i+1)/2;
            int sum2 = n*(n+1)/2 - (i-1)*i/2;
            if(sum1 == sum2) return i;
        }
        return -1;
    }
};