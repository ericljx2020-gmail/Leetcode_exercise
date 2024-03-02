class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> d(n);

        for (auto &e : edges){
            int a = e[0], b = e[1];
            g[a].push_back(b);
            d[b]++;
        }   
        int q[100005];
        int tt = -1;
        for (int i = 0; i < n; i++) {
            if (d[i] == 0) q[++tt] = i;
        }

        int res = 0;
        while (tt != -1) {
            int t = q[tt--];
            res++;
            for (int i = 0; i < g[t].size(); i++){
                int c = g[t][i];
                d[c]--;
                if (d[c] == 0) q[++tt] = c;
            }
        }
        return res == n;
    }
};