class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int dp[n][n];
        memset(dp, 0, sizeof dp);
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++){
            for (int j = 0; j < triangle[i].size(); j++){
                int cur = 0x3f3f3f3f;
                if (j-1 >= 0) cur = min(cur, dp[i-1][j-1]);
                if (j < triangle[i].size()-1) cur = min(cur, dp[i-1][j]);
                dp[i][j] = triangle[i][j] + cur;
                // cout << dp[i][j] << " ";
            }
            // puts("");
        }
        int res = INT_MAX;
        for (int i = 0; i < triangle[n-1].size(); i++){
            res = min(res, dp[n-1][i]);
        }
        return res;
    }
};