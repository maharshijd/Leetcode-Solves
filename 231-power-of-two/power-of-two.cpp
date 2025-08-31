class Solution {
public:
    bool isPowerOfTwo(int n) {
        int flag =0;
        if(n<=0) return false;
        
        else{
            int dupli = n;

            while(dupli!=0){
                if(dupli == 1) {flag = 1;break;}
                if(dupli%2 == 0) dupli/=2;
                else {break;}
            }
        }
        if(flag == 1) return true;
        else return false;
    }
};