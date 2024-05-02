class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int idx = 0;
        int n = s.size();
        while (idx < n && s[idx] == ' '){
            idx++;
        }
        if (s[idx] == '-'){
            sign = -1;
            idx++;
        }else if (s[idx] == '+'){
            idx++;
        }
        long long res = 0;
        while (idx < n){
            if ('0' <= s[idx] && s[idx] <= '9'){
                res = res * 10 + (s[idx] - '0');
                if (res > INT_MAX && sign == -1){
                    res = INT_MIN;
                    return res;
                }else if (res > INT_MAX && sign == 1){
                    res = INT_MAX;
                    return res;
                }
            }else {
                return (res * sign);
            }
            idx++;

        }
        return res * sign;
    }
};