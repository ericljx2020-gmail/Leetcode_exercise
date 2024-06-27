class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> f(n+1, vector<int> (m+1, 0x3f3f3f3f));
        int res = 0x3f3f3f3f;
        for (int i = 0; i < m; i++){
            f[0][i] = grid[0][i];
            if (n == 1) res = min(res, f[0][i]);
        }
        for (int i = 1; i < n; i++){
            for (int j = 0; j < m; j++){
                int b = grid[i][j];        //走到的点
                for (int k = 0; k < m; k++){
                    int a = grid[i-1][k];   //从a点出发
                    f[i][j] = min(f[i][j], f[i-1][k]+moveCost[a][j]+b);
                }
                if (i == n-1) res = min(res, f[i][j]);
            }
        }
        return res;
    }
};