class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target) return true;
        vector<vector<int>> newMat = mat;
        for(int i=0;i<4;i++){
            newMat = rotate(newMat);
            if(newMat==target) return true;
        }
        return false;
    }
    vector<vector<int>> rotate(vector<vector<int>>& mat){
        vector<vector<int>> rotated;
        int n=mat.size();
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(mat[j][i]);
            }
            rotated.push_back(temp);
        }
        reverse(rotated.begin(),rotated.end());
        return rotated;
    }
};