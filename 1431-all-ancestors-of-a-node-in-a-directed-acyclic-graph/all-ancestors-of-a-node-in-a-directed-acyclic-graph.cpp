class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n), g(n);
        unordered_map<int, int> st,in;
        unordered_map<int, unordered_map<int, int>> hash;
        for (auto e : edges){
            in[e[1]]++;
            g[e[0]].push_back(e[1]);
        }
        queue<int> q;
        for (int i = 0; i < n; i++){
            if (!in[i]){
                q.push(i);
                st[i] = 1;
            }
        }
        while (q.size()){
            int t = q.front();
            q.pop();
    
            for (int i = 0; i < g[t].size(); i++){
                int j = g[t][i];
                for (auto anc : res[t]){
                    if (hash[j][anc]) continue;
                    res[j].push_back(anc);
                    hash[j][anc] = 1;
                }
                res[j].push_back(t);
                hash[j][t] = 1;
                in[j]--;
            }

            for (int i = 0; i < n; i++){
                if (!st[i] && !in[i]){
                    q.push(i);
                    st[i] = 1;
                }
            }

        }
        for (int i = 0; i < n; i++){
            sort(res[i].begin(), res[i].end());
            // res[i].erase(unique(res[i].begin(), res[i].end()), res[i].end());
        }
        return res;
    }
};