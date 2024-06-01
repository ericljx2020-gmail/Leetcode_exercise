class Solution {
public:
    long long distributeCandies(int n, int l) {
        if (l * 3 < n) return 0;
        int a = min(n, l);
        long long res = 0;
        while (a >= 0){
            int bc = n-a;
            if (bc <= l){
                res += bc+1;
            }else{
                res += max(0,(bc+1)-2*(bc-l));
            }
            // cout << res <<" " ;
            a--;
        }
        return res;
    }
};