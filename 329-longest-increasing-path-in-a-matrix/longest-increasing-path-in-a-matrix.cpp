class Solution {
public:
    int n,m;
    unordered_map<int, unordered_map<int, int>> cache;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    vector<vector<int>> matrix;
    int longestIncreasingPath(vector<vector<int>>& _matrix) {
        matrix = _matrix;
        n = matrix.size(), m = matrix[0].size();
        int res = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!cache[i][j]){
                    dfs(i,j);
                }
                res = max(res, cache[i][j]);
            }
        }
        return res;
    }

    int dfs(int x, int y){
        if (cache[x][y]) return cache[x][y];
        int res = 0;
        for (int i = 0; i < 4; i++){
            int a = x + dx[i];
            int b = y + dy[i];
            if (a < 0 || b < 0 || a >= n || b >= m) continue;
            if (matrix[a][b] <= matrix[x][y]) continue;
            res = max(res, dfs(a,b));
        }
        res += 1;           //加上自己的长度
        cache[x][y] = res;
        return res;
    }

};