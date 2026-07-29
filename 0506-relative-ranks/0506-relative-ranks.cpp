class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        if(n==1) return {"Gold Medal"};
        if(n==2){
            if(score[0]>score[1]) return {"Gold Medal","Silver Medal"};
            else return {"Silver Medal", "Gold Medal"};
        }
        vector<int> temp = score;
        vector<int> pos(n);
        vector<string> standings(n);
        int count = 1;
        sort(temp.begin(),temp.end());
        for(int i = n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(temp[i] == score[j]) pos[j] = count++;
            }
        }
        for(int i=0;i<n;i++){
            if(pos[i] == 1) standings[i] = "Gold Medal";
            else if(pos[i] == 2) standings[i] = "Silver Medal";
            else if(pos[i] == 3) standings[i] = "Bronze Medal";
            else standings[i] = to_string(pos[i]);
        }
        return standings;
    }
};