class Solution {
public:
    int uniquePaths(int m, int n) {
        int f[m+1][n+1];
        memset(f, 0, sizeof f);
        f[0][1] = 1;
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
        return f[m][n];
    }
};