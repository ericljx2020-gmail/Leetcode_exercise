class Solution {
public:
    vector<vector<int>> g;
    int n;
    unordered_map<int, bool> st;
    int maximumDetonation(vector<vector<int>>& bombs) {
        n = bombs.size();
        g.resize(n, vector<int> (0,0));
        for (int i = 0; i < n; i++){
            auto &a = bombs[i];
            for (int j = 0; j < n; j++){
                if (i == j) continue;
                auto &b = bombs[j];
                double distance = sqrt((long long) (b[0]-a[0]) * (b[0]-a[0]) + (long long)(b[1]-a[1]) * (b[1]-a[1]));
                if (distance <= (double) a[2]) {
                    g[i].push_back(j);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++){
            st[i] = 1;
            int cur = dfs(i);
            // cout << cur << " ";
            res = max(res, cur);
            st.clear();
            // for (int j = 0; j < n; j++) cout << st[j] << " ";
            // puts("");
        }
        return res;
    }

    int dfs(int t){
        int res = 1;
        for (int i = 0; i < g[t].size(); i++){
            int j = g[t][i];
            if (st[j]) continue;
            st[j] = 1;
            res += dfs(j);
        }
        return res;
    }
};