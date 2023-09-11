class Solution {
public:
    int bs(long long a){
        int l = 0, r = 1 << 16;
        while (l < r){
            long long mid = l + r + 1 >> 1;
            if (mid * mid <= a){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        return r;
    }
    int mySqrt(int x) {
        return bs((long long)x);
    }
};