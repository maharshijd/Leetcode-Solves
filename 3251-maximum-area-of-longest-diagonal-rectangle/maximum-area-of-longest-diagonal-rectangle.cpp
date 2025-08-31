class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double diagLen = sqrt((dimensions[0][0]*dimensions[0][0]) + (dimensions[0][1]*dimensions[0][1]));
        vector<int> dim = {dimensions[0][0],dimensions[0][1]};
        int n = dimensions.size();
        for(int i =0;i< n;i++){
            double cal = sqrt((dimensions[i][0]*dimensions[i][0]) + (dimensions[i][1]*dimensions[i][1]));
            if(cal > diagLen){
                diagLen = cal;
                dim[0] = dimensions[i][0];
                dim[1] = dimensions[i][1];
            }
            else if(cal == diagLen){
                if(dim[0] * dim[1] < dimensions[i][1]*dimensions[i][0]){
                    dim[0] = dimensions[i][0];
                    dim[1] = dimensions[i][1];
                }
            }
        }
        return (dim[0] * dim[1]);
    }
};