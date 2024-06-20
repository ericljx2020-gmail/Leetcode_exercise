class Solution {
public:

    vector<vector<int>> res;
    vector<int> cur;
    int sum = 0;
    int k,n;
    unordered_map<int, int> st;
    void dfs(int t, int c){
        if (t == k) {
            if (sum == n){
                res.push_back(cur);
            }
            return;
        }

        for (int i = c; i < 10; i++){
            if (!st[i]){
                st[i] = 1;
                cur.push_back(i);
                sum += i;
                dfs(t+1, i+1);
                cur.pop_back();
                st[i] = 0;
                sum -= i;
            }
        }
    }

    vector<vector<int>> combinationSum3(int _k, int _n) {
        k = _k, n = _n;
        dfs(0, 1);
        return res;
    }
};