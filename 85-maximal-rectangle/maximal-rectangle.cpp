class Solution {
public:
    int maximalRectangle(vector<vector<char>>& h) {
        int n = h.size(), m = h[0].size();
        vector<vector<int>> f(n+1, vector<int> (m+1, 0));
        //f[i,j]表示以matrix[i,j]为底的1的高度
        //f[i,j] 两种情况1. h[i][j] = 1的话f[i][j] = f[i-1][j]+1;
        //f[i][j] = 0 if h[i][j] = 0
        for (int i = 0; i < m; i++)
            if (h[0][i] == '1') f[0][i] = 1;
            else f[0][i] = 0;
        for (int i = 1; i < n; i++){
            for (int j = 0; j < m; j++){
                if (h[i][j] == '1') f[i][j] = f[i-1][j] + 1;
                else f[i][j] = 0;
            }
        }
        vector<vector<int>> rs(n, vector<int> (m, 0)), ls(n, vector<int> (m, 0));
        for (int i = 0; i < n; i++) {
            //处理每一行
            int stk[2*m];
            int tt = -1;
            for (int j = 0; j < m; j++){
                while (tt != -1 && f[i][j] < f[i][stk[tt]]) {
                    rs[i][stk[tt--]] = j;
                }
                stk[++tt] = j;
            }
            while (tt != -1){
                rs[i][stk[tt--]] = m;
            }

            for (int j = m-1; j >= 0; j--) {
                while (tt != -1 && f[i][j] < f[i][stk[tt]]) {
                    ls[i][stk[tt--]] = j;
                }
                stk[++tt] = j;
            }
            while (tt != -1) {
                ls[i][stk[tt--]] = -1;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) {
                res = max(res, f[i][j] * (rs[i][j]-ls[i][j]-1));
            }
        }
        return res;
    }
};