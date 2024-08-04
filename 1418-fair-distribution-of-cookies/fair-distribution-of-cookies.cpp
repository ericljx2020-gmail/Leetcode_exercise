class Solution {
public:
    vector<int> v;
    unordered_map<int, int> st;
    int res = INT_MAX;
    int n;
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        v.resize(n, 0);
        dfs(0,k, cookies);
        return res;
    }

    void dfs(int t, int k, vector<int> cookies){
        if (t == n){
            int maxv = 0;
            for (int i = 1; i <= k; i++){
                maxv = max(maxv, st[i]);
            }
            res = min(res, maxv);
            return;
        }
        for (int i = 1; i <= k; i++){
            st[i] += cookies[t];
            if (st[i] < res) dfs(t+1, k, cookies);
            st[i] -= cookies[t];
        }
    }
};