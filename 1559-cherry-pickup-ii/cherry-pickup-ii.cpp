class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int f[n+1][m+1][m+1];
        memset(f, -0x3f, sizeof f);
        int res = 0;
        // for (int i = 0; i < m; i++){
        //     for (int j = 0; j < m; j++){
        //         f[0][i][j] += grid[0][i];
        //         if (i != j) f[0][i][j] += grid[0][j];
        //         cout << f[0][i][j] << " ";
        //     }
        // }
        f[0][0][m-1] = grid[0][0] + grid[0][m-1];
        int dx[3] = {-1,0,1};
        for (int r = 1; r < n; r++){
            for (int i = 0; i < m; i++){
                for (int j = 0; j < m; j++){
                    for (int k = 0; k < 3; k++){
                        for (int l = 0; l < 3; l++){
                            int pi = i+dx[k], pj = j+dx[l];
                            if (pi < 0 || pi >= m || pj < 0 || pj >= m) continue;
                            f[r][i][j] = max(f[r][i][j], f[r-1][pi][pj]);
                        }
                    }
                    f[r][i][j] += grid[r][i];
                    if (i != j) f[r][i][j] += grid[r][j];
                    if (r == n-1) res = max(res, f[r][i][j]);
                    // if (r == n-1) cout << f[r][i][j] << " ";
                }
            }
        }
        return res;
    }
};