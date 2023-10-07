class Solution {
public:
    int integerBreak(int n) {
        int res = 1;
        for (int i = 1; i <= n; i++){
            int sub = n;
            int cur = 1;
            while (sub - i > 1){
                sub -= i;
                cur *= i;
                res = max(res, cur);
                cout << cur << " ";
            }
            if (sub == n) continue;
            cur *= sub;
            res = max(res, cur);
            cout << cur << endl;
        }
        return res;
    }
};