class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        int f[n+5][m+5];
        int g[n+1][m+1];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                g[i][j] = obstacleGrid[i-1][j-1];
            }
        }
        f[1][1] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (!g[i-1][j]) f[i][j] += f[i-1][j];
                if (!g[i][j-1]) f[i][j] += f[i][j-1];
            }
        }
        if (g[n][m] || g[1][1]) return 0;
        return f[n][m];
    }
};