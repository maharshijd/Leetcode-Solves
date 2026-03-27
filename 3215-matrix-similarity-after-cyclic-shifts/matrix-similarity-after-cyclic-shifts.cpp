class Solution {
public:
    vector<int> rotateLeft(vector<int>& nums,int k){
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        reverse(nums.begin(), nums.end());
        return nums;
    }
    vector<int> rotateRight(vector<int>& nums,int k){
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        return nums;
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> newMat = mat;
        for(int i=0;i<mat.size();i++){
            if(i%2==0) newMat[i] = rotateLeft(newMat[i],k);
            else newMat[i] = rotateRight(newMat[i],k);
        }
        return mat == newMat;
    }
};