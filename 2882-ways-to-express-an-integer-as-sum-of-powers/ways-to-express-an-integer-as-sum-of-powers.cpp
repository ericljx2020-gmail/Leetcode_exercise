class Solution {
public:

    const int MOD = 1e9+7;

    int numberOfWays(int n, int x) {
        vector<int> v;
        for (int i = 1; i <= n; i++){
            int c = pow(i, x);
            if (c <= n) v.push_back(c);
            else break;
        }
        vector<long long> f(n+1, 0);
        f[0] = 1;
        for (int i = 0; i < v.size(); i++){
            for (int j = n; j >= v[i]; j--){
                f[j] += f[j-v[i]] % MOD;
            }
        }
        return (int) (f[n] % MOD);
    }

    int pow(int x, int n){
        int res = 1;
        for (int i = 0; i < n; i++) res *= x;
        return res;
    }
};