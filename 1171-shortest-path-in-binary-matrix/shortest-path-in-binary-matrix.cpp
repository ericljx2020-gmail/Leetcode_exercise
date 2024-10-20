class Solution {
public:
    int dx[8] = {0,0,-1,-1,-1,1,1,1};
    int dy[8] = {1,-1,0,-1,1,-1,0,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int n = grid.size(), m = grid[0].size();
        if (grid[0][0] == 1) return -1;
        q.push({0,0,1});
        unordered_map<int, unordered_map<int, int>> st;
        st[0][0] = 1;
        while (q.size()) {
            auto t = q.front();
            q.pop();

            int x = t[0], y = t[1], l = t[2];
            if (x == n-1 && y == m-1) return l;
            for (int i = 0; i < 8; i++) {
                int a = x + dx[i];
                int b = y + dy[i];
                if (a < 0 || b < 0 || a >= n || b >= m) continue;
                if (st[a][b]) continue;
                if (grid[a][b]) continue;
                q.push({a,b,l+1});
                st[a][b] = 1;
                if (a == n-1 && b == m-1) return l+1;
            }
        }
        return -1;
    }
};