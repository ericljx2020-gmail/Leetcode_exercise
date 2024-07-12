class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int q[100000];
        int tt = -1, hh = 0;
        int n = blocks.size();
        int cnt = 0;
        int res = INT_MAX;
        for (int i = 0; i < n; i++){
            if (hh <= tt && q[hh] < i-k+1){
                cnt -= (blocks[q[hh++]] == 'W');
            }
            q[++tt] = i;
            cnt += (blocks[i] == 'W');

            if (i >= k-1){
                res = min(res, cnt);
            }
        }
        return res;
    }
};