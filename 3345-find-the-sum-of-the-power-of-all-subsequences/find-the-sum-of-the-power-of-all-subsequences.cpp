class Solution {
public:
    const int N = 1e2+5, MOD = 1e9+7;
    int sumOfPower(vector<int>& nums, int k) {
        //f[i][j][c]: 只能用前i个数，体积为j，选了c个数的方案数量
        long long res = 0;
        long long f[N][N];          //优化掉一维
        memset(f, 0, sizeof f);
        f[0][0] = 1;            //体积为0，选了0个数的方案数量为1

        for (int i = 0; i < nums.size(); i++){
            for (int j = k; j >= nums[i]; j--){
                for (int c = nums.size(); c > 0; c--){
                    f[j][c] = (f[j][c] + f[j-nums[i]][c-1]) % MOD;
                }
            }
        }

        int pow2 = 1;
        for (int i = nums.size(); i > 0; i--) {
            res = (res + (long long) f[k][i] * pow2) % MOD;
            pow2 = pow2 * 2 % MOD;
        }   
        return res;
    }
};