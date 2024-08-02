class Solution {
public:
    int n,m;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    unordered_map<int, unordered_map<int, bool>> st;

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        n = grid.size(), m = grid[0].size();
        BFS(row, col, color, grid);
        return grid;
    }

    void BFS(int x, int y, int c, vector<vector<int>>& grid){
        int orig_c = grid[x][y];
        queue<vector<int>> q;
        q.push({x,y});
        st[x][y] = 1;

        while (q.size()){
            auto t = q.front();
            q.pop();
            bool border = false;

            for (int i = 0; i < 4; i++){
                int a = t[0] + dx[i];
                int b = t[1] + dy[i];

                if (a < 0 || a >= n || b < 0 || b >= m){
                    border = true;
                    continue;
                }
                if (st[a][b]) continue;
                if (grid[a][b] != orig_c){
                    border = true;
                    continue;
                }
                st[a][b] = 1;
                q.push({a,b});
            }

            if (border == true) grid[t[0]][t[1]] = c;
        }
        return;
    }
};