class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x){
            if (x > 0 && res > (INT_MAX - x % 10) / 10) return 0;
            //跟INT_MIN比较的时候res和x都是负数所以相当于INT_MIN + abs(x)
            if (x < 0 && res < (INT_MIN - x % 10) / 10) return 0;
            res *= 10;
            res += x % 10;
            x /= 10;
        }

        return res;
    }
};