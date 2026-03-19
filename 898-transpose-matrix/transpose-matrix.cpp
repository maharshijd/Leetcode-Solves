class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> newMat;
        int row = matrix.size(),col=matrix[0].size();
        for(int i=0;i<col;i++){
            vector<int> temp;
            for(int j=0;j<row;j++){
                temp.push_back(matrix[j][i]);
            }
            newMat.push_back(temp);
        }
        return newMat;
    }
};