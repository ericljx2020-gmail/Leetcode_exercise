class Solution {
public:
    vector<string> g;
    vector<vector<string>> ans;
    unordered_map<int, int> col, dg, udg;
    void dfs(int u, int n){
        if (u == n) {
            ans.push_back(g);
            return ;
        }

        for (int i = 0; i < n; i++){
            if (!col[i] && !dg[i+u] && !udg[n+i-u]){
                col[i] = dg[i+u] = udg[n+i-u] = 1;
                g[u][i] = 'Q';
                dfs(u+1,n);
                g[u][i] = '.';
                col[i] = dg[i+u] = udg[n+i-u] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string s = "";
        for (int i = 0; i < n; i++) s += '.';

        for (int i = 0; i < n; i++){
            g.push_back(s);
        }

        dfs(0,n);

        return ans;
    }
};