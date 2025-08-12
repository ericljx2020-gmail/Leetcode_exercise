class Solution {
public:
    int MOD = 1e9+7;
    int numberOfWays(int n, int x) {
        int top = 0;
        while (pow(top+1, x) <= n) {
            top ++;
        }
        // cout << top;
        vector<int> f(n+1, 0);
        f[0] = 1;           // 0 way to form 0
        for(int j = 1; j <= top; j++){
            for (int i = n; i >= 1; i--){
                int d = pow(j,x);
                if (i < d) break; 
                f[i] = (f[i] + f[i-d]) % MOD;
                // cout << f[i] << " ";
            }
        }
        return f[n];
    }
};