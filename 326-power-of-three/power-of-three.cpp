class Solution {
public:
    bool isPowerOfThree(int n) {
        int flag =0;
        if(n<=0) return false;
        
        else{
            int dupli = n;

            while(dupli!=0){
                if(dupli == 1) {flag = 1;break;}
                if(dupli%3 == 0) dupli/=3;
                else {break;}
            }
        }
        if(flag == 1) return true;
        else return false;
    }
};