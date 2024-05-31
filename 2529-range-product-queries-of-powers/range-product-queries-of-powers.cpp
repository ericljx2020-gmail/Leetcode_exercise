class Solution {
public:
    const int MOD = 1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> v,f;
        // v.push_back(0);
        for (int i = 0; i <= 31; i++){
            if (n >> i & 1){
                v.push_back(1 << i);
                cout << (1 << i) << " ";
            }
        }
        vector<int> res;
        for (auto q : queries) {
            int a = 1;
            for (int i = q[0]; i <= q[1]; i++) {
                a = a * v[i] % MOD;
            }
            res.push_back(a);
        }
        return res;
    }
};