class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            string temp = words[i];
            //int flag =0;
            for(int j=0;j<words[i].size();j++){
                if(temp[j] == x){
                    //flag = 1;
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};