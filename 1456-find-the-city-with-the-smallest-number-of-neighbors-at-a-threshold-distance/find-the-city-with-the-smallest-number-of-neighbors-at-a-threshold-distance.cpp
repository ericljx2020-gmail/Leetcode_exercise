class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        int g[101][101], f[101][101];
        memset(f, 0x3f, sizeof f);
        memset(g, 0x3f, sizeof g);
        for (int i = 0; i < n; i++){
            g[i][i] = 0;
        }
        for (auto e : edges){
            int a = e[0], b = e[1], c = e[2];
            g[a][b] = g[b][a] = min(g[a][b], c);
        }

        for (int k = 0; k < n; k++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        int res = INT_MAX, p = -1;
        for (int i = 0; i < n; i++){
            int cnt = 0;
            for (int j = 0; j < n; j++){
                if (g[i][j] <= d) cnt++;
            }
            if (cnt <= res){
                res = cnt;
                p = i;
            }
        }
        return p;
    }
};