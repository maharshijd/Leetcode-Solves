class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int,int>> robots;
        for(int i=0;i<n;i++){
            robots.push_back({positions[i],i});
        }
        sort(robots.begin(),robots.end());
        stack<int> st;
        for(int k=0;k<robots.size();k++){
            int pos = robots[k].first;
            int i = robots[k].second;
            if(directions[i] == 'R'){
                st.push(i);
            }
            else{
                while(!st.empty() && healths[i] > 0){
                    int j = st.top();
                    if(healths[j] < healths[i]){
                        st.pop();
                        healths[i]--;
                        healths[j] = 0;
                    }
                    else if(healths[j] > healths[i]){
                        healths[j]--;
                        healths[i]=0;
                        break;
                    }
                    else{
                        st.pop();
                        healths[i]=0;
                        healths[j]=0;

                        break;
                    }
                } 
            }

        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(healths[i] > 0){
                res.push_back(healths[i]);
            }
        }
        return res;
    }
};