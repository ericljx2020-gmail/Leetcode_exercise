class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_map<int, unordered_map<int, bool>> rol, col, g;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') continue;
                int cur = board[i][j] - '0';
                int oneD = i / 3 * 3 + j / 3;
                if (g[oneD][cur] || rol[i][cur] || col[j][cur]) {
                    return false; 
                }
                g[oneD][cur] = rol[i][cur] = col[j][cur] = 1;
            }
        }
        return true;
    }
};