class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if (n==0) return "";
        int min = strs[0].length();
        string temp = strs[0];
        for(int i=0;i<n;i++){
            if(strs[i].length()<min) {
                min = strs[i].length();
                temp = strs[i];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<temp.length();j++){
                if(strs[i][j] == temp[j]) continue;
                else{
                    temp = temp.substr(0,j);
                    break;
                }
            }
        }
        return temp;

    }
};