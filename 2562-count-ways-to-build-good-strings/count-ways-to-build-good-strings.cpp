class Solution {
public:
    const int MOD = 1e9+7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> f(high+1, 0);
        f[0] = 1;
        long long res = 0;
        for (int i = 1; i <= high; i++){
            if (i >= zero){
                f[i] = (f[i] + f[i-zero]) % MOD;
            }
            if (i >= one){
                f[i] = (f[i] + f[i-one]) % MOD;
            }
            if (i >= low) res += f[i] % MOD;
        }
        return (int)(res % MOD);
    }
};