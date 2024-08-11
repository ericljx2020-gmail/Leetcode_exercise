class Solution {
public:
    vector<vector<vector<int>>> g;
    int m;
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        m = rides.size();
        g.resize(n+1);

        for (auto r : rides){
            g[r[1]].push_back({r[0], r[2]});
        }
        vector<long long> f(n+1, 0);
        for (int i = 1; i <= n; i++){
            f[i] = f[i-1];
            for (int j = 0; j < g[i].size(); j++){
                auto t = g[i][j];
                f[i] = max(f[i], (long long) f[t[0]] + i-t[0]+t[1]);
            }
            // cout << f[i] << " ";
        }
        return f[n];
    }
};