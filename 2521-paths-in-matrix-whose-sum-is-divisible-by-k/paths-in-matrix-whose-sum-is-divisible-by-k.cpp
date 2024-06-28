class Solution {
public:
    const int MOD = 1e9+7;
    int numberOfPaths(vector<vector<int>>& grid, int l) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> f(n, vector<vector<int>> (m, vector<int> (l, 0)));
        f[0][0][grid[0][0] % l] = 1;

        for (int i = 1; i < n; i++){
            int r = grid[i][0] % l;
            for (int k = 0; k < l; k++){
                f[i][0][k] += f[i-1][0][((k-r) % l + l) % l];
            }
        }

        for (int j = 1; j < m; j++){
            int r = grid[0][j] % l;
            for (int k = 0; k < l; k++){
                f[0][j][k] += f[0][j-1][((k-r) % l + l) % l];
            }
        }

        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                int r = grid[i][j];
                for (int k = 0; k < l; k++){
                    f[i][j][k] = (f[i][j][k] + f[i-1][j][((k-r) % l + l) % l]) % MOD;
                    f[i][j][k] = (f[i][j][k] + f[i][j-1][((k-r) % l + l) % l]) % MOD;
                }
            }
        }
        return f[n-1][m-1][0] % MOD;
        // cout << f[0][0][2] << ' ' << f[0][1][1] << " " << f[0][2][2];
        // cout << f[0][0][2] << " " << f[1][0][2] << " " << f[2][0][2];
        // return 0;
    }
};