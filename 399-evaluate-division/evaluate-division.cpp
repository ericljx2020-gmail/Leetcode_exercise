class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_set<string> vers;
        unordered_map<string, unordered_map<string, double>> d;

        for (int i = 0; i < equations.size(); i++){
            auto a = equations[i][0], b = equations[i][1];
            d[b][a] = values[i];
            d[a][b] = 1 / values[i];
            vers.insert(a), vers.insert(b);
        }

        for (auto k : vers){
            for (auto i : vers) {
                for (auto j : vers){
                    if (d[i][k] && d[k][j]){
                        d[i][j] = d[i][k] * d[k][j];
                    }
                }
            }
        }
        vector<double> res;
        for (int i = 0; i < queries.size(); i++){
            auto a = queries[i][0], b = queries[i][1];
            if (d[b][a]) res.push_back(d[b][a]);
            else res.push_back(-1.0);
        }
        return res;
    }
};