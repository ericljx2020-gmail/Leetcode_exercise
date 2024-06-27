class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> f(n+1, vector<int> (m+1, 0x3f3f3f3f));
        int res = INT_MAX;
        for (int i = 0; i < m; i++){
            f[0][i] = grid[0][i];
            if (0 == n-1) res = min(res, grid[0][i]);
        }

        for (int i = 1; i < n; i++){
            for (int j = 0; j < m; j++){
                for (int k = 0; k < m; k++){
                    if (j == k) continue;
                    f[i][j] = min(f[i][j], f[i-1][k] + grid[i][j]);
                }
                if (i == n-1) res = min(res, f[i][j]);
            }
            // puts("");
        }
        return res;
    }
};

// [[-73,61,43,-48,-36],
// [3,30,27,57,10],
// [96,-76,84,59,-15],
// [5,-49,76,31,-7],
// [97,91,61,-46,67]]