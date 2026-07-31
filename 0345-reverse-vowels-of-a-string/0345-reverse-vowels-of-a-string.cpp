class Solution {
public:
    string reverseVowels(string s) {
        vector<char> v_start;
        vector<int> pos;
        for(int i=0;i<s.size();i++){
            char temp = tolower(s[i]);
            if(temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u'){
                v_start.push_back(s[i]);
                pos.push_back(i);
            }
        }
        reverse(v_start.begin(),v_start.end());
        for(int i=0;i<pos.size();i++){
            s[pos[i]] = v_start[i];
        }
        return s;
    }
};