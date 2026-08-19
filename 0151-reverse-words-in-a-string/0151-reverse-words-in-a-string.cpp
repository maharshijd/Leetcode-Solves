class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.size();
        for(int i=0;i<n;i++){
            string temp = "";
            int x=i;
            while(s[x] != ' ' && x<n){
                temp = temp + s[x];
                x++;
            }
            i=x;
            if(temp != "") words.push_back(temp);
        }
        reverse(words.begin(),words.end());
        string ans = "";
        for(int i=0;i<words.size();i++){
            ans = ans + words[i];
            ans = ans + ' ';
        }
        ans.pop_back();
        return ans;
    }
};