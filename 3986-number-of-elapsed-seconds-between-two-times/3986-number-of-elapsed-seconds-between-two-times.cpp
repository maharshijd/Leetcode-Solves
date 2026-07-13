class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        string temp = "";
        temp += startTime[0];
        temp += startTime[1];
        int x = stoi(temp);
        temp = "";
        temp += endTime[0];
        temp += endTime[1];
        int y = stoi(temp);
        int hrDiff = y-x;
        temp = "";
        temp += startTime[3];
        temp += startTime[4];
        x = stoi(temp);
        temp = "";
        temp += endTime[3];
        temp += endTime[4];
        y = stoi(temp);
        int minDiff = y-x;
        temp = "";
        temp += startTime[6];
        temp += startTime[7];
        x = stoi(temp);
        temp = "";
        temp += endTime[6];
        temp += endTime[7];
        y = stoi(temp);
        int secDiff = y-x;
        return secDiff + (minDiff*60) + (hrDiff * 60 * 60);
    }
};