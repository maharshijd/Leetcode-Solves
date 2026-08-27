class Solution {
public:
    string addStrings(string num1, string num2) {
        int i,j;
        int m = num1.size(),n=num2.size();
        i=m-1,j=n-1;
        string ans = "";
        int carry=0;
        while(i>=0 && j>=0){
            int temp = (num1[i] - '0') + (num2[j] - '0') +carry;
            ans = to_string(temp%10) + ans;
            carry = temp/10;
            i--;
            j--;
        }
        while(i>=0){
            int temp = num1[i] - '0' + carry;
            ans = to_string(temp%10) + ans;
            carry = temp/10;
            i--;
        }
        while(j>=0){
            int temp = num2[j] - '0' +carry;
            ans = to_string(temp%10) + ans;
            carry = temp/10;
            j--;
        }
        if (carry) ans = to_string(carry) + ans;

        return ans;
    }
};