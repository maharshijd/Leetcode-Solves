class Solution {
public:
    int titleToNumber(string columnTitle) {
        int base = 26;
        long long int total =0;
        int len = columnTitle.size();
        for(int i=0;i<len;i++){
            int typecast = (int)columnTitle[i];
            typecast-=64;
            int val = typecast* pow(26,len - (i+1));
            total+=val;
        }
        return total;
    }
};