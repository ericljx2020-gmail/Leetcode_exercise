class Solution {
public:
    vector<vector<int>> f, w;
    int n,m;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        n = matrix.size(), m = matrix[0].size();
        w = matrix;
        f = vector(n, vector<int> (m, -1));
        int res = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                res = max(res, dp(i,j));
            }
        }
        return res;
    }

    int dp(int x, int y) {
        auto &v = f[x][y];
        if (v != -1) return v;

        v = 1;

        for (int i = 0; i < 4; i++){
            int a = x + dx[i];
            int b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (w[a][b] > w[x][y]) {
                v = max(v, dp(a,b)+1);
            }
        }
        return v;
        
    }

};