class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& preq) {
        vector<int> in(n, 0);
        vector<vector<int>> g(n);
        for (auto p : preq){
            in[p[0]]++;
            g[p[1]].push_back(p[0]);
        }

        queue<int> q;
        unordered_map<int, bool> st;
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (in[i] == 0) {
                q.push(i);
                st[i] = 1;
                cnt++;
            }
        }
        while (q.size()){
            auto t = q.front();
            q.pop();

            for (int i = 0; i < g[t].size(); i++){
                in[g[t][i]]--;
            }

            for (int i = 0; i < n; i++){
                if (!st[i] && in[i] == 0){
                    cnt++;
                    q.push(i);
                    st[i] = 1;
                }
            }
        }
        return cnt == n;
    }
};