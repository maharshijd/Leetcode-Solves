class Solution {
public:
    string processStr(string s) {
        string res;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(c>='a' && c<='z'){
                res.push_back(c);
            }
            else if(c == '*'){
                if (!res.empty()) {
                    res.pop_back();
                }
            }
            else if(c=='#'){
                res+=res;
            }
            else if(c=='%'){
                reverse(res.begin(),res.end());
            }
        }
        return res;
    }
};