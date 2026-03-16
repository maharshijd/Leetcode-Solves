class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        int sum=1;
        vector<vector<int>> triangle;
        for(int i=0;i<n;i++){
            sum=1;
            vector<int> temp;
            for(int j=0;j<=i;j++){
                temp.push_back(sum);
                sum = (sum*(i-j)/(j+1));
            }
            triangle.push_back(temp);
        }
        return triangle;
    }
};