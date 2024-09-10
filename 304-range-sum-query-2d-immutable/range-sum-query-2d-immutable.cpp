class NumMatrix {
public:
    vector<vector<int>> matrix, f;
    int n,m;
    NumMatrix(vector<vector<int>>& _matrix) {
        matrix = _matrix;
        n = matrix.size(), m = matrix[0].size();
        f.resize(n+1, vector<int> (m+1));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int x, int y, int a, int b) {
        x++;
        y++;
        a++;
        b++;
        int sum = f[a][b] - f[x-1][b] - f[a][y-1] + f[x-1][y-1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */