class Solution {
public:
    int numSquares(int n) {
        vector<int> v;
        for (int i = 1; i * i <= n; i++){
            v.push_back(i * i);
        }
        vector<int> f(n+1, 0x3f3f3f3f);
        f[0] = 0;
        for (int i = 0; i < v.size(); i++){
            for (int j = v[i]; j <= n; j++){
                f[j] = min(f[j], f[j-v[i]] + 1);
            }
        }
        return f[n];
    }
};