class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_map<int, bool>> row, col, grid;
        int n = board.size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == '.') continue;
                int g_r = i / 3, g_c = j / 3;
                int cur = board[i][j] - '0';
                int oneD = g_r * 3 + g_c;
                if (grid[oneD][cur] || row[i][cur] || col[j][cur]) return false;
                grid[oneD][cur] = row[i][cur] = col[j][cur] = 1;
            }
        }
        return true;
    }
};