class Solution {
public:
    static const int N = 1e4+4;
    int coinChange(vector<int>& coins, int amount) {
        int f[N];
        int n = coins.size();
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 1; i <= amount; i++){
            for (auto coin : coins){
                if (i-coin >= 0){
                    // cout << i << " " << coin << endl;
                    f[i] = min(f[i], f[i-coin]+1);
                }
            }
        }
        if (f[amount] > 0x3f3f3f3f / 2) return -1;
        return f[amount];
    }
};