class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int k) {
        int n = c.size();
        c.insert(c.begin(), 0);
        g.insert(g.begin(), 0);
        vector<int> cp(1,0), f(n+1,0);
        for (int i = 1; i <= n; i++){
            cp.push_back(c[i] * (1-g[i]));
        }
        //cp是原本grumpy * customer的前缀和
        for (int i = 1; i <= n; i++){
            f[i] = f[i-1] + cp[i];
        }
        // cout << f[n] << "\n";

        //用滑动窗口来计算每一个窗口可以加多少
        int cur = 0;
        int maxv = 0;
        int q[n+10];
        int tt = -1, hh = 0;
        for (int i = 1; i <= n; i++){
            if (hh <= tt && q[hh] < i-k+1){
                cur -= g[q[hh]] * c[q[hh]];        //如果g[q[hh]]是1的话说明本来就没有加，如果是0说明加了所以要剪掉
                hh++;
            }
            q[++tt] = i;
            cur += g[i] * c[i];
            if (i >= k) {
                maxv = max(maxv, cur);
                // cout << cur << " ";
            }
        }
        return maxv+f[n];
    }
};