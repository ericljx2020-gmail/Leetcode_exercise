class Solution {
public:
    unordered_map<int, unordered_map<int, bool>> row, col;
    int grid[3][3][9];
    void solveSudoku(vector<vector<char>>& board) {
        memset(grid, 0, sizeof grid);
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue;
                int cur = board[i][j] - '1';
                row[i][cur] = col[j][cur] = grid[i/3][j/3][cur] = 1;
            }
        }

        dfs(board, 0, 0);
    }

    bool dfs(vector<vector<char>>& board, int x, int y) {
        if (y == 9) x++, y = 0;
        if (x == 9) return true;

        if (board[x][y] != '.') return dfs(board, x, y+1);

        for (int i = 0; i < 9; i++){
            if (!row[x][i] && !col[y][i] && !grid[x/3][y/3][i]){
                board[x][y] = i + '1';
                row[x][i] = col[y][i] = grid[x/3][y/3][i] = 1;
                if (dfs(board, x, y+1)) return true;
                board[x][y] = '.';
                row[x][i] = col[y][i] = grid[x/3][y/3][i] = 0;
            }
        }
        return false;
    }
};