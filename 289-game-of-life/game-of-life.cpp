class Solution {
public:
    int dx[8] = {0,0,-1,-1,-1,1,1,1};
    int dy[8] = {-1,1,-1,0,1,-1,0,1};
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> g(n, vector<int> (m, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int cnt = 0;
                for (int k = 0; k < 8; k++){
                    int a = i + dx[k], b = j + dy[k];
                    if (a < 0 || a >= n || b < 0 || b >= m) continue;
                    cnt += board[a][b];
                }
                if (board[i][j] == 1){
                    if (cnt >= 2 && cnt < 4) g[i][j] = 1;
                }else{
                    if (cnt == 3) g[i][j] = 1;
                }
            }
        }
        board = g;
        return;
    }
};