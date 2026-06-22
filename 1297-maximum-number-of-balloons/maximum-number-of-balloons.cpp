class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count(26,0);
        for(int i=0;i<text.size();i++){
            count[text[i] - 'a']++;
        }
        return min({count['b'- 'a'],count['a'-'a'],count['l'-'a']/2,count['o'-'a']/2,count['n'-'a']});
    }
};