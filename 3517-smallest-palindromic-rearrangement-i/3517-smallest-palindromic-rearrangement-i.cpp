class Solution {
public:
    string smallestPalindrome(string s) {
        int f[26] = {0};

        for (char c : s)
            f[c - 'a']++;

        string left = "", right = "", mid = "";

        for (int i = 0; i < 26; i++) {
            while (f[i] >= 2) {
                left += char('a' + i);
                f[i] -= 2;
            }
            if (f[i] == 1)
                mid = char('a' + i);
        }

        right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};