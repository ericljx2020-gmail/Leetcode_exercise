class Solution {
public:
    const int MOD = 1e9+7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        //整体思路，先按照走格子dp做，计算出三个相邻个字过来的最大值以后，看看有几个最大值，将最大值格子记录的路径数相加即可，所以要两个dp数组，一个是记录路径数，一个记录最大值
        vector<vector<int>> f(n, vector<int> (n, 0)), g(n, vector<int> (n, 0));
        g[n-1][n-1] = 1;
        for (int j = n-2; j >= 0; j--){
            if (board[n-1][j] == 'X') {
                f[n-1][j] = INT_MIN;
                g[n-1][j] = 0;
                continue;
            }
            f[n-1][j] = f[n-1][j+1] + (board[n-1][j] - '0');
            g[n-1][j] = g[n-1][j+1];
        }
        for (int i = n-2; i >= 0; i--){
            if (board[i][n-1] == 'X') {
                f[i][n-1] = INT_MIN;
                g[i][n-1] = 0;
                continue;
            }
            f[i][n-1] = f[i+1][n-1] + (board[i][n-1] - '0');
            g[i][n-1] = g[i+1][n-1];
        }

        for (int i = n-2; i >= 0; i--){
            for (int j = n-2; j >= 0; j--){
                if (board[i][j] == 'X'){
                    f[i][j] = INT_MIN;
                    g[i][j] = 0;
                    continue;
                }
                f[i][j] = max(f[i+1][j+1], max(f[i+1][j], f[i][j+1]));
                if (f[i][j] == f[i+1][j+1]) g[i][j] = (g[i][j] + g[i+1][j+1]) % MOD;
                if (f[i][j] == f[i+1][j]) g[i][j] = (g[i][j] + g[i+1][j]) % MOD;
                if (f[i][j] == f[i][j+1]) g[i][j] = (g[i][j] + g[i][j+1]) % MOD;
                if (i == 0 && j == 0) continue;
                f[i][j] += (board[i][j] - '0');
            }
        }

        // for (int i = 0; i < n; i++){
        //     for (int j = 0; j < n; j++){
        //         cout << g[i][j] << " ";
        //     }
        //     puts("");
        // }
        return {f[0][0] < 0 ? 0 : f[0][0], g[0][0] % MOD};
    }
};