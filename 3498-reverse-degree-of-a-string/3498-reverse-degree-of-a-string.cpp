class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i =0;i<s.size();i++){
            int temp =s[i]-'a'+1;
            temp = 27-temp;
            sum +=temp*(i+1);
        }
        return sum;
    }
};