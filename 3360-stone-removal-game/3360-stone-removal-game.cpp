class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        int counter = 10;
        int turn = 0;
        while(n>=counter){
            if(turn == 0) turn = 1;
            else turn = 0;
            n -= counter;
            counter--;
        }
        return turn==1;
    }
};