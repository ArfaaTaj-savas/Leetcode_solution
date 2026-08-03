class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";

        bool sign = num < 0 ? true : false;
        num = abs(num);
        string ans = "";

        while(num){
            ans += (num % 7 + '0');
            num /= 7;
        }
        reverse(ans.begin(), ans.end());
        
        return sign ? "-"+ans : ans;
    }
};