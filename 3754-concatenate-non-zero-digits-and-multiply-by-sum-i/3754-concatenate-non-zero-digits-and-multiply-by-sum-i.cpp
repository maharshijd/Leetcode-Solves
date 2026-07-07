class Solution {
public:
    long long sumAndMultiply(int n) {
        int x=0;
        int sum =0;
        while(n!=0){
            int temp = n%10;
            if(temp!=0) x = x*10 + temp;
            sum+=temp;
            n/=10;
        }
        int y = 0;
        while(x!=0){
            int temp= x%10;
            y = y*10 + temp;
            x/=10;
        }

        return (long long)sum*y;

    }
};