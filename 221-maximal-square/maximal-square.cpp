class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int f[n+1][m+1];
        memset(f, 0, sizeof f);
        int res = 0;
        for (int i = 0; i < n; i++) f[i][0] = matrix[i][0] - '0', res = max(res, f[i][0]);
        for (int i = 0; i < m; i++) f[0][i] = matrix[0][i] - '0', res = max(res, f[0][i]);
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                if (matrix[i][j] == '1'){
                    f[i][j] = min(f[i-1][j], min(f[i][j-1], f[i-1][j-1])) + 1;
                    res = max(res, f[i][j]);
                }
                
            }
        }
        
        return res * res;
    }
};