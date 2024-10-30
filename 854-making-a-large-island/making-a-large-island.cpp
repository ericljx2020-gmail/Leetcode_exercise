class Solution {
public:
    int n,m;
    vector<int> f, sz;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int find(int x){
        if (f[x] != x) return f[x] = find(f[x]);
        return f[x];
    }

    int get(int x, int y){
        return x * m + y;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n * m; i++) {
            f.push_back(i);
            sz.push_back(1);
        }
        int res = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1){
                    // cout << grid[i][j] << " ";
                    int a = get(i,j);
                    for (int k = 0; k < 4; k++){
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (grid[nx][ny] == 0) continue;
                        cout << grid[nx][ny] << " ";
                        int b = get(nx,ny);
                        int fa = find(a), fb = find(b);
                        if (fa != fb){
                            f[fb] = fa;
                            sz[fa] += sz[fb];
                        }
                    }
                    puts("");
                    res = max(res, sz[find(a)]);
                }
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int b = get(i,j);
                int fb = find(b);
                // cout << fb << " ";
            }
            puts("");
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 0){
                    unordered_map<int, int> hash;
                    int a = get(i,j);
                    for (int k = 0; k < 4; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (grid[nx][ny] == 1){
                            int b = get(nx, ny);
                            int fb = find(b);
                            hash[fb] = sz[fb];
                        }
                    }
                    int cur = 1;
                    for (auto &[k,v] : hash){
                        cur += v;
                    }
                    res = max(res, cur);
                }
            }
        }
        return res;
    }
};
