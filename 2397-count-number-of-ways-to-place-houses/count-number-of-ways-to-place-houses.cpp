class Solution {
public:
    const int MOD = 1e9+7;
    int countHousePlacements(int n) {
        vector<vector<long long>> f(n+1, vector<long long> (2, 0));
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            f[i][0] = (f[i-1][1] + f[i-1][0]) % MOD;
            f[i][1] = f[i-1][0];
        }
        return (int) (f[n][0]+f[n][1]) * (f[n][0]+f[n][1]) % MOD;
    }
};