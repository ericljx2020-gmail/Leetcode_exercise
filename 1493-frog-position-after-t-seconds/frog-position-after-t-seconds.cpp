class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        target--;
        vector<vector<int>> g(n);
        unordered_map<int, bool> hash;          
        unordered_map<int, double> pos;
        for (auto e : edges){
            //无向图
            g[e[0]-1].push_back(e[1]-1);
            g[e[1]-1].push_back(e[0]-1);
        }

        queue<pair<int, int>> q;
        q.push({0, 0});             //0号点，第0步
        pos[0] = 1;
        hash[0] = 1;
        while (q.size()){
            auto tt = q.front();
            q.pop();
            // cout << tt.first << " ";
            int p = tt.first, step = tt.second;
            if (step == t) break;
            bool flag = 0;          //记录这个点是否有更新
            for (int i = 0; i < g[p].size(); i++){
                int j = g[p][i];
                if (hash[j]) continue;
                hash[j] = 1;
                flag = 1;
                if (p == 0) pos[j] = pos[p] / (g[p].size());
                else pos[j] = pos[p] / (g[p].size()-1);
                q.push({j, step+1});
            }
            if (flag) pos[p] = 0;       //保留叶子结点的值确保最后不走了也能返回答案
        }

        return pos[target];

    }
};