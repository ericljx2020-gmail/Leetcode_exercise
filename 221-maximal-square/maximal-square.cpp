class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> f(n+1, vector<int> (m+1,0));
        int res = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (i == 0 || j == 0) {
                    f[i][j] = (int)(matrix[i][j] == '1');
                    res = max(res, f[i][j]);
                    continue;
                }
                if (matrix[i][j] == '1') f[i][j] = min(f[i-1][j]+1, min(f[i][j-1]+1, f[i-1][j-1]+ 1));
                else{
                    f[i][j] = 0;
                }
                res = max(res, f[i][j]);

            }
        }

        return res * res;
    }
};