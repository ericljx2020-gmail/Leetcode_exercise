class Solution {
public:
    int minimumPartition(string s, int k) {
        int n = s.size();
        s = ' ' + s;
        vector<int> f(n+1, INT_MAX);

        /*
        * f[i]：从1-i中分的最小substr数量
        * f[i]可以从f[i-1], f[i-2], ..., f[i-k]转移过来，条件是
        * s[i-k, i]的value < k， 所以我们对于每一个地方求出最小值就可以
        */

        int d = 0;
        int kk = k;
        while (kk){
            d++;
            kk /= 10;
        }
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = max(1,i-d+1); j <= i; j++) {
                // cout << s.substr(j, i-j+1) <<" " ;
                int c = stoi(s.substr(j, i-j+1));
                if (c > k) continue;
                f[i] = min(f[i], f[j-1]);
            }
            if (f[i] == INT_MAX) return -1;
            f[i]++;
            // puts("");
        }

        return f[n];
    }
};