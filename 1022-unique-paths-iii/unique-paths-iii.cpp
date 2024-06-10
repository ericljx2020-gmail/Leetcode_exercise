class Solution {
public:
    vector<vector<int>> grid;
    int n,m;
    int obs = 0;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int dfs(int x, int y, int st){ 
        if (grid[x][y] == 2){
            // cout << st << ' ';
            return st == m * n - obs;
        }
        // cout << x << " " << y << "\n";
        int res = 0;
        grid[x][y] = -1;
        for (int i = 0; i < 4; i++){
            int a = x + dx[i];
            int b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            // cout << a << ' ' << b << "\n";
            if (grid[a][b] == -1) continue;
            
            // grid[a][b] = -1;
            res += dfs(a,b,st+1);
            // grid[a][b] = 0;
        }
        grid[x][y] = 0;
        return res;
    }

    int uniquePathsIII(vector<vector<int>>& _grid) {
        grid = _grid;
        n = grid.size() , m = grid[0].size();
        int x,y;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1){
                    x = i, y = j;
                }
                if (grid[i][j] == -1){
                    obs++;
                }
            }
        }
        // grid[x][y] = -1;
        return dfs(x,y,1);
    }
};