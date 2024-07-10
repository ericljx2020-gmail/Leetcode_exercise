class Solution {
public:
    const int N = 1e2+5, MOD = 1e9+7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        //f[i][j][k]表示只用前i个人，用人不超过j，profit至少为k的方案数量
        //f[i][j][k] = f[i-1][j][k] 不选i
        //f[i][j][k] += f[i-1][j-group[i]][max(k-profit[i])] 选i的情况
        long long f[N][N][N];          
        memset(f, 0, sizeof f);
        for (int i = 0; i <= n; i++){
            f[0][i][0] = 1;     //前0个用任何多人profit至少是k都有一种情况
        }

        for (int i = 1; i <= group.size(); i++){
            for (int j = 0; j <= n; j++){
                for (int k = 0; k <= minProfit; k++){
                    f[i][j][k] = f[i-1][j][k];      //不选
                    if (j >= group[i-1]){
                        f[i][j][k] =(f[i][j][k] + f[i-1][j-group[i-1]][max(0,k-profit[i-1])]) % MOD;
                    }
                }
            }
        }
        return (int)f[group.size()][n][minProfit];
    }
};