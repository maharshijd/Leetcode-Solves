class Solution {
public:
    int scoreOfString(string s) {
        int score =0;
        for(int i=0;i<s.size()-1;i++){
            int val1 = s[i];
            int val2 = s[i+1];
            score += abs(val2-val1);
        }
        return score;
    }
};