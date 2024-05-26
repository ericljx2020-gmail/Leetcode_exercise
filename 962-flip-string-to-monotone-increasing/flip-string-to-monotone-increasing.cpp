class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<vector<int>> f(n+1, vector<int> (2, 0));
        //f[i][0]表示第i位为0的最小flip数
        //f[i][1]表示第i位为1的最小flip数
        //f[i][0]的话，前面不能有1所以f[i][0] = f[i-1][0] + (s[i] == '1')
        //f[i][1]有两种情况，一种是前面全是1，第二种是这是第一个1，所以要去min
        for (int i = 1; i <= n; i++){
            f[i][0] = f[i-1][0] + (s[i] == '1');
            f[i][1] = min(f[i-1][1] + (s[i] == '0'), f[i-1][0] + (s[i] == '0'));
            // cout << f[i][0] << " " << f[i][1] << '\n';
        }
        return min(f[n][1], f[n][0]);
    }
};