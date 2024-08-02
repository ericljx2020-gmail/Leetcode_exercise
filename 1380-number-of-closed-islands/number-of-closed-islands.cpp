class Solution {
public:
    int n,m;
    unordered_map<int, unordered_map<int, bool>> st;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int res = 0;
        vector<vector<int>> v;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                // cout << grid[i][j] << " " ;
                if (!st[i][j] && grid[i][j] == 0){
                    bool cur = BFS(i,j, grid);
                    if (cur) v.push_back({i,j});
                    res += cur;
                }
            }
            // puts("");
        }
        // for (auto c : v){
        //     cout << c[0] << " " << c[1] << '\n';
        // }
        return res;
    }

    bool BFS(int x, int y, vector<vector<int>> grid){
        queue<vector<int>> q;
        q.push({x,y});
        st[x][y] = 1;
        bool flag = true;

        while (q.size()){
            auto t = q.front();
            q.pop();

            for (int i = 0; i < 4; i++){
                int a = t[0] + dx[i];
                int b = t[1] + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m){
                    flag = false;
                    continue;
                }
                if (st[a][b]) continue;
                if (grid[a][b] == 1) continue;
                st[a][b] = 1;
                q.push({a,b});
            }
        }
        return flag;
    }
};