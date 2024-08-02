class Solution {
public:
    int n,m;
    unordered_map<int, unordered_map<int, bool>> st;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int findMaxFish(vector<vector<int>>& grid) {
        int res = 0;
        n = grid.size(),  m = grid[0].size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!st[i][j] && grid[i][j] > 0){
                    // cout << 1 << " ";
                    res = max(res, BFS(i,j,grid));
                }
            }
        }
        // cout << BFS(0,1,grid);
        return res;
    }

    int BFS(int x, int y, vector<vector<int>> grid){
        queue<vector<int>> q;
        q.push({x,y});
        st[x][y] = 1;
        int cnt = grid[x][y];

        while (q.size()){
            auto t = q.front();
            q.pop();

            for (int i = 0; i < 4; i++){
                int a = t[0] + dx[i];
                int b = t[1] + dy[i];

                if (a < 0 || a >= n || b < 0 || b >= m) continue;
                if (st[a][b]) continue;
                if (grid[a][b] == 0) continue;

                cnt += grid[a][b];
                st[a][b] = 1;
                q.push({a,b});
            }
        }
        return cnt;
    }
};