class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int> occurence;
        occurence.reserve(26);
        for(char i = 'a';i<='z';i++){
            occurence[i] = 0;
        }
        for(int i = 0;i<sentence.size();i++)
        {
            occurence[sentence[i]]++;
        }
        for(char i='a';i<='z';i++){
            if(occurence[i] == 0) return false;
        }
        return true;

    }
};