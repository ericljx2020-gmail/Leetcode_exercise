class Solution {
public:
    unordered_map<int, int> d;
    vector<vector<int>> v;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        v.resize(n, vector<int> (0));
        for (auto e : edges) {
            d[e[0]]++;
            d[e[1]]++;
            v[e[0]].push_back(e[1]);
            v[e[1]].push_back(e[0]);
        }
        queue<int> q1, q2;
        for (int i = 0; i < n; i++){
            if (d[i] == 1){
                q1.push(i);
            }
        }
        vector<vector<int>> res;
        while (q1.size() || q2.size()){
            res.push_back({});
            if (q1.size()){
                while (q1.size()) {
                    int t = q1.front();
                    q1.pop();
                    res[res.size()-1].push_back(t);
                    for (auto j : v[t]) {
                        d[j]--;
                        if (d[j] == 1){
                            q2.push(j);
                        }
                    }
                }
            }else{
                while (q2.size()) {
                    int t = q2.front();
                    q2.pop();
                    res[res.size()-1].push_back(t);
                    for (auto j : v[t]) {
                        d[j]--;
                        if (d[j] == 1) {
                            q1.push(j);
                        }
                    }
                }
            }
        }
        return res[res.size()-1];
    }
};