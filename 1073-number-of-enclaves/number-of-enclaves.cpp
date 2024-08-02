class Solution {
public:
    int n,m;
    unordered_map<int, unordered_map<int, bool>> st;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};

    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!st[i][j] && grid[i][j] == 1){
                    res += bfs(i,j,grid);
                }
            }
        }    
        return res;
    }

    int bfs(int x, int y, vector<vector<int>> grid){
        int cnt = 1;
        bool flag = false;
        queue<vector<int>> q;
        q.push({x,y});
        st[x][y] = 1;

        while (q.size()){
            auto t = q.front();
            q.pop();

            for (int i = 0; i < 4; i++){
                int a = t[0] + dx[i];
                int b = t[1] + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m) {
                    flag = true;
                    continue;
                }
                if (st[a][b]) continue;
                if (grid[a][b] == 0) continue;
                st[a][b] = 1;
                cnt++;
                q.push({a,b});
            }
        }
        return !flag ? cnt : 0;
    }
};