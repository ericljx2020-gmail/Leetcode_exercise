class Solution {
public:
    int n,m;
    unordered_map<int, unordered_map<int, int>> pacific, atlantic, st1, st2;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        for (int i = 0; i < n; i++){
            if (!st1[i][0]){
                dfs1(i,0, heights);
            }
            if (!st2[i][m-1]){
                dfs2(i, m-1, heights);
            }
        }
        for (int i = 0; i < m; i++){
            if (!st1[0][i]){
                dfs1(0,i, heights);
            }
            if (!st2[n-1][i]){
                dfs2(n-1, i, heights);
            }
        }
        vector<vector<int>> v;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (atlantic[i][j] && pacific[i][j]) v.push_back({i,j});
            }
        }
        return v;

    }

    void dfs1(int x, int y, vector<vector<int>> heights){
        queue<vector<int>> q;
        q.push({x,y});
        st1[x][y] = 1;
        pacific[x][y] = 1;

        while (q.size()){
            auto t = q.front();
            q.pop();

            for (int i = 0; i < 4; i++){
                int a = t[0] + dx[i];
                int b = t[1] + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m) continue;
                if (st1[a][b]) continue;
                if (heights[a][b] < heights[t[0]][t[1]]) continue;
                q.push({a,b});
                st1[a][b] = 1;
                pacific[a][b] = 1;
            }
        }
    }

    void dfs2(int x, int y, vector<vector<int>> heights){
        queue<vector<int>> q;
        q.push({x,y});
        st2[x][y] = 1;
        atlantic[x][y] = 1;

        while (q.size()){
            auto t = q.front();
            q.pop();

            for (int i = 0; i < 4; i++){
                int a = t[0] + dx[i];
                int b = t[1] + dy[i];
                
                if (a < 0 || a >= n || b < 0 || b >= m) continue;
                if (st2[a][b]) continue;
                if (heights[a][b] < heights[t[0]][t[1]]) continue;
                st2[a][b] = 1;
                q.push({a,b});
                atlantic[a][b] = 1;
            }
        }
    }
};