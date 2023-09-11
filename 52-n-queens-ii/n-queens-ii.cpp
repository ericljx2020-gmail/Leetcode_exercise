class Solution {
public:
    static const int N = 10;
    int ans = 0;
    int g[N][N], col[N], dg[2*N], udg[2*N];
    void dfs(int u, int n){
        if (u == n) {
            ans ++;
            return;
        }

        for (int i = 0; i < n; i++){
            if (col[i] || dg[u+i] || udg[n-u+i]) continue;
            col[i] = dg[u+i] = udg[n-u+i] = 1;
            dfs(u+1, n);
            col[i] = dg[u+i] = udg[n-u+i] = 0;
        }


    }
    int totalNQueens(int n) {
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                g[i][j] = 0;
            }
        }
        memset(col,0,sizeof col);
        memset(dg, 0, sizeof dg);
        memset(udg, 0, sizeof udg);
        dfs(0,n);
        return ans;
    }
};