class Solution {
public:
    bool isPalindrome(int x) {
        long newNum=0;
        long dupli = x;
        if(x<0) return false;
        else{
            while(dupli!=0){
                newNum = newNum*10 + dupli%10;
                dupli/=10;
            }
            if(newNum==x) return true;
            else return false;
        }
    }
};