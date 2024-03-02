class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int> res, d(n);
        vector<vector<int>> g(n);

        for (auto &e : edges) {
            int a = e[0], b = e[1];
            g[b].push_back(a);
            d[a]++;
        }
        queue<int>q;
        for (int i = 0; i < n; i++){
            if (d[i] == 0) q.push(i);
        }
        int cnt = 0;
        while (q.size()){
            int t = q.front();
            q.pop();
            res.push_back(t);
            cnt++;

            for (int i = 0; i < g[t].size(); i++){
                int b = g[t][i];
                d[b]--;
                if (d[b] == 0) q.push(b);
            }
        }

        if (cnt == n) return res;
        return {};
    }
};