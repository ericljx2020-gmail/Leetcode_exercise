class Solution {
public:

    const int MOD = 1e9+7;
    int concatenatedBinary(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++){
            int flag = false;
            string s = "";
            for (int j = 31; j >= 0; j--) {
                if (i >> j & 1 || flag){
                    flag = true;
                    s += to_string(i >> j & 1);
                }
            }
            // cout << s.size() << " ";
            for (int j = 0; j < s.size(); j++) {
                ans = ans * 2 % MOD;
                // cout << ans << ' ';    
            }
            ans = ans + i % MOD;
            // cout << ans << " ";
            // puts("");
        }
        
        return ans;
    }
};