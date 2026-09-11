// lol learnt it in class 12th
class Solution {
public:
    int factorial(int n){
        if(n == 0) return 1;

        int fact = 1;
        while(n >= 1){
            fact *= n;
            n--;
        }
        return fact;
    }
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int> mp;
        for(int i = 0; i < digits.size(); i++){
            mp[digits[i]]++;
        }
        int ans = 0;
        for(int i = 0; i <= 9; i++){
            if(mp[i] == 0 || i % 2 != 0) continue;
            mp[i]--;
            for(int j = 1; j <= 9; j++){
                if(mp[j] == 0) continue;
                mp[j]--;
                for(int k = 0; k <= 9; k++){
                    if(mp[k] > 0) ans++;
                }
                mp[j]++;
            }
            mp[i]++;
        }
        return ans;
    }
};
