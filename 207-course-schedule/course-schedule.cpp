class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        unordered_map<int, int> in;
        vector<vector<int>> g(n);
        for (auto c : p){
            in[c[0]]++;
            g[c[1]].push_back(c[0]);
        }
        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (in[i] == 0) {
                q.push(i);
            }
        }
        while (q.size()){
            auto t = q.front();
            cnt++;
            q.pop();

            for (int i = 0; i < g[t].size(); i++){
                auto j = g[t][i];
                in[j]--;
                if (in[j] == 0) q.push(j);
            }
        }
        return cnt == n;
    }
};