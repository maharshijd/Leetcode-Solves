class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int res;
        for(int i =0;i<matrix.size();i++){
            if((target > matrix[i][0] && target< matrix[i][matrix[i].size()-1]) || target == matrix[i][0] ||target == matrix[i][matrix[i].size()-1]){
                res = bsearch(matrix[i],target);
                if(res != -1){
                    break;
                }
            }
        }
        if(res != -1){
            return true;
        }
        else return false;
    }
    int bsearch(vector<int> arr,int target){
        int low = 0,high = arr.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid] == target) return mid;
            else if(arr[mid]>target) high = mid-1;
            else low = mid +1;
        }
        return -1;
    }
};