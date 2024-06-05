class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++){
            if (grid[i][0] == 0){
                for (int j = 0; j < grid[i].size(); j++){
                    grid[i][j] ^= 1;
                }
            }
        }

        for (int j = 0; j < m; j++) {
            int c0 = 0, c1 = 0;
            for (int i = 0; i < n; i++){
                c0 += (grid[i][j] == 0);
                c1 += (grid[i][j] == 1);
            }
            if (c0 > c1){
                for (int i = 0; i < n; i++){
                    grid[i][j] ^= 1;
                }
            }
        }

        int res = 0;

        for (int i = 0; i < n; i++){
            int idx = 0, cur = 0;
            for (int j = m-1; j >= 0; j--){
                cur += grid[i][j] << idx;
                idx++;
            }
            res += cur;
        }
        return res;
    }
};