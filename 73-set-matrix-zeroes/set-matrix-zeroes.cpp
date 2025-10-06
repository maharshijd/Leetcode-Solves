class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> checks;
        
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] ==0){
                    checks.push_back({i,j});
                }
            }
        }
        for(int k=0;k<checks.size();k++){
            for(int i=0;i<m;i++){
                matrix[i][checks[k][1]] = 0;
            }
            for(int j=0;j<n;j++){
                matrix[checks[k][0]][j] = 0;
            }
        }
    }
};