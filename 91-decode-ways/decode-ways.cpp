class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<vector<int>> f(n+1, vector<int> (2, 0));
        //f[i][0] 如果i不取的种类
        //f[i][1] 如果i取的种类

        f[0][0] = 1;
        f[0][1] = (int)(s[0]-'0' <= 26 && s[0]-'0' >= 1);
        for (int i = 1; i < n; i++) {
            if (s[i] != '0') f[i][0] = f[i-1][1];
            if (s[i] != '0')f[i][1] = f[i-1][1];
            if (s[i-1] != '0' && stoi(s.substr(i-1, 2)) <= 26 && stoi(s.substr(i-1, 2)) >= 1){
                f[i][1] += f[i-1][0];
            }    
        }
        // cout << stoi(" 1");
        // cout << f[1][0] << " " << f[1][1] << " " << f[0][1];
        return f[n-1][1];
    }
};