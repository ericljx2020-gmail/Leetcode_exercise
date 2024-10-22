class Solution {
public:
    double myPow(double x, int _n) {
        long long n = _n;
        if (x == 1) return 1;
        if (x == -1) return n % 2 == 0 ? 1 : -1;
        if (n == 0) return 1;
        if (n < 0) {
            n = -n;
            x = 1/x;
        }
        double cx = x;
        long long l = 1;
        int cnt = 0;
        while (l+l < n){
            l += l;
            cnt++;
        }
        int r = n-l;
        while (cnt--){
            x *= x;
        }
        cout << x << " " << r;
        while (r > 0){
            x *= cx;
            r--;
        }
        return x;
    }
};