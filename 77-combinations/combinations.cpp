class Solution {
public:
    vector<vector<int>> res;
    // unordered_map<int, bool> hash;
    vector<int> cur;
    void dfs(int c, int a, int n, int k){
        if (c > k){
            res.push_back(cur);
            return;
        }

        for (int i = a; i <= n; i++){
            cur.push_back(i);
            dfs(c+1, i+1, n, k);
            cur.pop_back(); 
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(1,1,n,k);
        return res;
    }
};