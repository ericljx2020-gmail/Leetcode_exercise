class Solution {
public:
    const int MOD = 1e9+7;

    int countTexts(string s) {
        int n = s.size();
        s = " " + s;
        vector<int> f(n+1, 0);
        f[0] = 1;
        for (int i = 1; i <= n; i++){
            int k = 3;
            if (s[i] == '7' || s[i] == '9') k = 4;
            for (int j = i; j >= i-k; j--){
                f[i] = (f[i] + f[j]) % MOD;
                if (s[j] != s[i]) break;
            }
        }
        return f[n] % MOD;
    }
};