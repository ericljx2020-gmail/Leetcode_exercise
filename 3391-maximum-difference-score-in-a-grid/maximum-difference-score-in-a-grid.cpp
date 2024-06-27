class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> f(n+1, vector<int> (m+1, 0));
        f[0][0] = 0;
        int res = INT_MIN;
        for (int i = 1; i < n; i++){
            f[i][0] = max(f[i-1][0], 0) + (grid[i][0] - grid[i-1][0]);
            res = max(res, f[i][0]);
        }
        for (int j = 1; j < m; j++){
            f[0][j] = max(f[0][j-1], 0) + (grid[0][j] - grid[0][j-1]);
            res = max(res, f[0][j]);
        }
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                f[i][j] = max(max(f[i-1][j], 0) + grid[i][j] - grid[i-1][j], max(f[i][j-1], 0) + grid[i][j] - grid[i][j-1]);
                res = max(res, f[i][j]);
            }
        }
        return res;
    }
};