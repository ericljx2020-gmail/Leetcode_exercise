class Solution {
public:
    const int MOD = 1e9+7;
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> in;
        for (auto road : roads){
            in[road[0]]++;
            in[road[1]]++;
        }
        vector<int> v;
        for (auto x : in){
            v.push_back(x.second);
        }
        sort(v.begin(), v.end(), [&](int a, int b){
            return a > b;
        });
        long long res = 0;
        for (int i = 0; i < v.size(); i++){
            res += (long long)n * v[i];   
            n--;
        }
        return res;
    }
};