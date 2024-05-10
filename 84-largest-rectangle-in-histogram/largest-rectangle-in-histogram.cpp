class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        int stk[n+10];
        int tt = -1;
        vector<int> rs(n+1, 0), ls(n+1, 0);
        //找每一个数右边第一个比自己小的数字
        for (int i = 0; i < n; i++) {
            while (tt != -1 && h[i] < h[stk[tt]]){
                rs[stk[tt--]] = i;
            }
            stk[++tt] = i;
        }
        while (tt != -1){
            rs[stk[tt--]] = n;
        }
        for (int i = n-1; i >= 0; i--) {
            while (tt != -1 && h[i] < h[stk[tt]]) {
                ls[stk[tt--]] = i;
            }
            stk[++tt] = i;
        }
        while (tt != -1){
            ls[stk[tt--]] = -1;
        } 
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, h[i] * (rs[i] - ls[i]-1));
        }
        return res;
    }
};