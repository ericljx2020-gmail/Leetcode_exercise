class Solution {
public:
    static const int N = 1e3+5;
    int g[N][N], dist[N];
    unordered_map<int, bool> st;
    int n;
    bool flag = 0;
    int res = 0;
    void prim(){
        memset(dist, 0x3f, sizeof dist);

        for (int i = 0; i < n; i++) {
            int t = -1;
            for (int j = 0; j < n; j++){
                if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
            }
            if (i && dist[t] == 0x3f3f3f3f) {
                flag = 1;
                return;
            }

            if (i){
                res += dist[t];
            }

            for (int j = 0; j < n; j++){
                dist[j] = min(dist[j], g[t][j]);
            }
            st[t] = 1;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        n = points.size();
        int idx = 0;
        memset(g, 0x3f, sizeof g);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int a = points[i][0], b = points[i][1], c = points[j][0], d = points[j][1];
                if (i == j) continue;
                g[i][j] = g[j][i] = min(g[i][j], abs(a-c) + abs(b-d));
            }
        }
        prim();
        return res;
    }
};