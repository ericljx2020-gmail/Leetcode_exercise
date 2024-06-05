class Solution {
public:
    int maxScore(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> f(n+1, vector<int> (m+1, 0));
        f[0][0] = 0;
        int maxr = -1;
        int maxo = INT_MIN;
        bool flag = false;
        for (int i = 1; i < n; i++){
            f[i][0] = max(0, f[i-1][0] + (g[i][0] - g[i-1][0]));
            maxr = max(maxr, f[i][0]);
            maxo = max(maxo, g[i][0] - g[i-1][0]);
            if (g[i][0] >= g[i-1][0]) flag = true;
        }
        for (int j = 1; j < m; j++){
            f[0][j] = max(0, f[0][j-1] + (g[0][j] - g[0][j-1]));
            maxr = max(maxr, f[0][j]);
            maxo = max(maxo, g[0][j] - g[0][j-1]);
            if (g[0][j] >= g[0][j-1]) flag = true;
        }
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                f[i][j] = max(f[i][j], max(f[i-1][j] + (g[i][j]-g[i-1][j]), f[i][j-1] + (g[i][j] - g[i][j-1])));
                maxr = max(maxr, f[i][j]);
                maxo = max(maxo, max(g[i][j]-g[i-1][j], g[i][j]-g[i][j-1]));
                if (g[i][j] >= g[i-1][j] || g[i][j] > g[i][j-1]) flag = true;
            }
        }
        if (flag) return maxr;
        return maxo;
    }
};