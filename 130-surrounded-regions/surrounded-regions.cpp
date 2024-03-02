class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    unordered_map<int, unordered_map<int, bool>> vis;
    void bfs(int x, int y, bool flip, vector<vector<char>>& board, int n, int m){
        queue<pair<int, int>> q;
        q.push({x,y});
        vis[x][y] = 1;
        while (q.size()){
            auto t = q.front();
            q.pop();
            if (flip) board[t.first][t.second] = 'X';
            for (int i = 0; i < 4; i++){
                int a = t.first + dx[i], b = t.second + dy[i];
                if (a >= n || a < 0 || b >= m || b < 0) continue;
                if (vis[a][b]) continue;
                if (board[a][b] == 'X') continue;
                q.push({a,b});
                vis[a][b] = 1;
            }
        }
    }    

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if ((i == 0 || i == n-1 || j == 0 || j == m-1) && board[i][j] == 'O'){
                    bfs(i,j,0, board, n,m);
                }
            }
        }
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!vis[i][j]){
                    bfs(i,j,1,board,n,m);
                }
            }
        }
        return;
    }
};