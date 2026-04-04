class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        vector<char> str(s.begin(), s.end());
        vector<char> fin(goal.begin(), goal.end());
        if (str == fin) return true;
        for (int k = 1; k < str.size(); k++) {
            vector<char> temp = str;
            reverse(temp.begin(), temp.end());
            reverse(temp.begin(), temp.begin() + k);
            reverse(temp.begin() + k, temp.end());
            if (temp == fin) return true;
        }
        return false;
    }
};