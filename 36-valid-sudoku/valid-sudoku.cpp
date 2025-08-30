class Solution {
public:
    int twoDimensionToOne(int x, int y){
        return 3*x+y;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> row, col, grid;
        // process row
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue;
                int c = board[i][j] - '0';
                if (row[i].find(c) == row[i].end()){
                    row[i].insert(c);
                }else{
                    return false;
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++){
                if (board[j][i] == '.') continue;
                int c = board[j][i] - '0';
                if (col[i].find(c) == col[i].end()){
                    col[i].insert(c);
                }else{
                    return false;
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int x = i / 3;
                int y = j / 3;
                int pos = twoDimensionToOne(x,y);
                int c = board[i][j] - '0';
                if (grid[pos].find(c) == grid[pos].end()) {
                    grid[pos].insert(c);
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};