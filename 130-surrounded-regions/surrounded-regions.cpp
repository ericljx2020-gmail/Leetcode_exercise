class Solution {
public:
    vector<vector<char>> b;
    int n,m;
    unordered_map<int, unordered_map<int,int>> st;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    void bfs(int i, int j){
        st[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});

        while (q.size()){
            pair<int,int> t = q.front();
            q.pop();

            for (int i = 0; i < 4; i++){
                int nx = t.first+dx[i], ny = t.second+dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (b[nx][ny] == 'X') continue;
                if (st[nx][ny]) continue;

                q.push({nx,ny});
                st[nx][ny] = 1;
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        b = board;
        if (b.size() == 0) return;
        n = b.size(), m = b[0].size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (i == 0 || j == 0 || i == n-1 || j == m-1){
                    if (b[i][j] == 'O'){
                        bfs(i,j);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (b[i][j] == 'O' && !st[i][j]){
                    b[i][j] = 'X';
                }
            }
        }
        board = b;
        return;
    }
};