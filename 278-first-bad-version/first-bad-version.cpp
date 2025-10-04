// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1,right = n;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(isBadVersion(mid) == true){
                while(isBadVersion(mid) == true){
                    if(mid == 1) return 1;
                    else mid = mid-1;
                }
                return mid+1;
            }
            else{
                left = mid+1;
            }
        }
        return -1;
    }

};