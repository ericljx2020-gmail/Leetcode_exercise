class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int stones = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                stones += grid[i][j];
            }
        }
        if (k >= m + n - 2 || k >= stones) return m+n-2;

        queue<vector<int>> q;
        unordered_map<int, unordered_map<int, unordered_map<int, bool>>> hash;

        q.push({0,0,k});
        hash[0][0][k] = 1;
        int lenth = 1;
        int p = q.size();
        while (p--){
            auto t = q.front();
            q.pop();

            for (int i = 0; i < 4; i++){
                int a = t[0] + dx[i];
                int b = t[1] + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m) continue;
                if (grid[a][b] == 0 && hash[a][b][t[2]] == 0){
                    if (a == n-1 && b == m-1) return lenth;
                    q.push({a,b,t[2]});
                    hash[a][b][t[2]] = 1;
                }else if (grid[a][b] == 1 && t[2] > 0 && hash[a][b][t[2]-1] == 0){
                    q.push({a,b,t[2]-1});
                    hash[a][b][t[2]-1] = 1;
                }
            }

            if (p == 0) {
                p = q.size();
                lenth ++;
            }
        }
        return -1;
    }
};