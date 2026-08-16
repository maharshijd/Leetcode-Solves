class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int minDist = 1000;
        int j=-1;
        for(int i=0;i<drones.size();i++){
            int temp = abs(drones[i][0] - target[0]) + abs(drones[i][1]-target[1]);
            int range = drones[i][2];
            if(temp<=range && temp < minDist){
                minDist = temp;
                j=i;
            }
        }
        return j;
    }
};