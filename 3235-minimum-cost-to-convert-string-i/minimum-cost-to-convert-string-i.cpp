class Solution {
public:
    static const int N = 27;
    int g[N][N], f[N][N];
    int n;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        memset(g, 0x3f, sizeof g);
        memset(f, 0x3f, sizeof f);
        for (int i = 0; i < original.size(); i++){
            int a = original[i] - 'a';
            int b = changed[i] - 'a';
            g[a][b] = min(g[a][b], cost[i]);
        }
        
        for (int k = 0; k < 26; k++){
            for (int i = 0; i < 26; i++){
                for (int j = 0; j < 26; j++){
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
                // cout << g[i][j] << " ";
            }
            // puts("");
        }
        long long res = 0;
        for (int i = 0; i < source.size(); i++){
            int a = source[i]-'a';
            int b = target[i]-'a';
            if (a == b) continue;
            if (g[a][b] == 0x3f3f3f3f) return -1;
            res += g[a][b];
        }
        return res;
    }
};