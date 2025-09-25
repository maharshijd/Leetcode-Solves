class Solution {
public:
    int strStr(string haystack, string needle) {

        if (needle.empty()) {
            return 0;
        }
        
        int n = haystack.size();
        int m = needle.size();
        
        for (int i = 0; i <= n - m; i++) { 
            bool flag = true;  
            
            for (int j = 0; j < m; j++) {
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            
            if (flag) {
                return i; 
            }
        }
        
        return -1;
    }
};
