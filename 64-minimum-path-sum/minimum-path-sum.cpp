class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int g[n+1][m+1];
        int dp[n+1][m+1];
        memset(dp, 0, sizeof dp);
        memset(g, 0, sizeof g);
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                g[i][j] = grid[i-1][j-1];
            }
        }
        for (int i = 1; i <= n; i++) dp[i][0] = INT_MAX;
        for (int i = 1; i <= m; i++) dp[0][i] = INT_MAX;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (i == 1 && j == 1) {
                    dp[i][j] = g[i][j];
                    continue;
                }
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] += g[i][j];
                cout << dp[i][j] << " ";
            }
            puts("");
        }
        return dp[n][m];
    }
};