class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    bool flag = false;
    unordered_map<int, unordered_map<int,int>> hash;
    void dfs(int x, int y, vector<vector<char>>& board, string word, int idx){
        if (flag) return;
        if (idx == word.size()-1){
            flag = true;
            return;
        };
        for (int i = 0; i < 4; i++){
            int a = x + dx[i], b = y + dy[i];
            if (a >= board.size() || b >= board[0].size() || a < 0 || b < 0) continue;
            if (hash[a][b]) continue;
            if (board[a][b] == word[idx+1]){
                hash[a][b] = 1;
                dfs(a,b,board, word, idx+1);
                hash[a][b] = 0;
            }
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        int t = word.size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] == word[0]){
                    hash[i][j] = 1;
                    dfs(i,j,board, word, 0);
                    hash[i][j] = 0;
                    if (flag) return true;
                }
            }
        }
        return false;
    }
};