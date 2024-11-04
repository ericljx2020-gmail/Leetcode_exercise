class Solution {
public:
    double myPow(double x, int n) {
        typedef long long ll;
        double res = 1;
        bool isminus = n < 0;
        for (ll k = abs(ll(n)); k; k >>= 1){
            if (k & 1) res *= x;
            x *= x;
        }
        if (isminus) return 1/res;
        return res;
    }
};