class Solution {
public:
    unordered_map<int, bool> col, dg, udg;
    vector<string> g;
    vector<vector<string>> ans;
    void dfs(int u, int n){
        if (u == n){
            ans.push_back(g);
        }

        for (int i = 0; i < n; i++){
            if (!col[i] && !dg[u+i] && !udg[n+i-u]){
                col[i] = dg[u+i] = udg[n+i-u] = 1;
                g[u][i] = 'Q';
                dfs(u+1, n);
                col[i] = dg[u+i] = udg[n+i-u] = 0;
                g[u][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string s = "";
        for (int i = 0; i < n; i++) s += '.';
        for (int i = 0; i < n; i++) g.push_back(s);
        dfs(0, n);
        return ans;
    }
};