class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int dist = 0;
        int blanks = 0;
        for (char c : moves) {
            if (c == 'L')
                dist--;
            else if (c == 'R')
                dist++;
            else
                blanks++;
        }
        return abs(dist) + blanks;
    }
};
