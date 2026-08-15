class Solution {
public:
    int hammingWeight(int n) {
        string bin = intToBin(n);
        int count = 0;
        for(char c : bin){
            if(c == '1') count++;
        }
        return count;
    }
    string intToBin(int n) {
        string binary = "";
        while (n > 0) {
            binary = char('0' + n % 2) + binary;
            n = n / 2;
        }
        return binary;
    }
};