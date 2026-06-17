class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c >= 'a' && c <= 'z') {
                len++;
            } else if (c == '*') {
                if (len > 0)
                    len--;
            } else if (c == '#') {
                len *= 2;
            }
        }
        if (k >= len)
            return '.';
        for (int i = s.size(); i >= 0; i--) {
            char c = s[i];
            if (c >= 'a' && c <= 'z') {
                if (k == len - 1)
                    return c;
                len--;
            } else if (c == '*') {
                len++;
            } else if (c == '#') {
                len /= 2;
                if (k >= len)
                    k -= len;
            } else if (c == '%') {
                k = len - k - 1;
            }
        }
        return '.';
    }
};