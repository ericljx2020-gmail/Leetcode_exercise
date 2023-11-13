class Solution {
public:
    vector<vector<char>> g;
    int n, m;
    int cnt = 0;
    unordered_map<int, unordered_map<int,int>> st;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    void bfs(int x, int y){
        st[x][y] = 1;
        queue<pair<int,int>>q;
        q.push({x,y});

        while (q.size()){
            pair<int,int> t = q.front();
            q.pop();

            for (int i = 0; i < 4; i++){
                int a = t.first+dx[i], b = t.second+dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m) continue;
                if (g[a][b] == '0') continue;
                if (st[a][b]) continue;

                q.push({a,b});
                st[a][b] = 1;
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        g = grid;
        if (g.size() == 0) return 0;
        n = g.size(), m = g[0].size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (g[i][j] == '1' && !st[i][j]){
                    bfs(i,j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};