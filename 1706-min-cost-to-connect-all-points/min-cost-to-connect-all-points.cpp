class Solution {
public:
    static const int N = 1e3+5;
    struct node{
        int x,y,w;
    }edges[N*N];
    static bool cmp(node a, node b){
        return a.w < b.w;
    }
    int f[N];
    int find(int x){
        if (f[x] == x) return x;
        return f[x] = find(f[x]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int idx = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int a = points[i][0], b = points[i][1], c = points[j][0], d = points[j][1];
                edges[idx++] = {i, j, abs(a-c) + abs(b-d)};
            }
        }
        sort(edges, edges+idx, cmp);
        int res = 0;
        for (int i = 0; i < n; i++) f[i] = i;
        for (int i = 0; i < idx; i++){
            int x = edges[i].x, y = edges[i].y, w = edges[i].w;
            int fx = find(x), fy = find(y);
            if (fx != fy){
                f[fx] = fy;
                res += w;
            }
        }
        return res;
    }
};