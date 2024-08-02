class Solution {
public:
    unordered_map<int, unordered_map<int, bool>> st;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int n,m;
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!st[i][j] && grid[i][j] == '1'){
                    bfs(i,j,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }

    void bfs(int x, int y, vector<vector<char>>& grid){
        queue<vector<int>> q;
        q.push({x,y});
        st[x][y] = 1;
        while (q.size()){
            auto t = q.front();
            q.pop();

            for (int i = 0; i < 4; i++){
                int a = dx[i] + t[0], b = dy[i] + t[1];
                if (a < 0 || a >= n || b < 0 || b >= m) continue;
                if (st[a][b]) continue;
                if (grid[a][b] == '0') continue;
                st[a][b] = 1;
                q.push({a,b});
            }
        }
    }
};