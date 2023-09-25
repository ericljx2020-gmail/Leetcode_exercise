class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        h.push_back(0);
        h.insert(h.begin(),0);
        int asc[n+5], desc[n+5];
        for (int i = 0; i <= n; i++) asc[i] = n+1, desc[i] = 0;
        int q[n+10];
        int tt = -1;
        for (int i = 0; i <= n+1; i++){
            while (tt != -1 && h[q[tt]] > h[i]){
                asc[q[tt]] = i;
                tt--;
            }
            q[++tt] = i;
        }
        tt = -1;
        for (int i = n+1; i >= 0; i--){
            while (tt != -1 && (h[q[tt]] > h[i])){
                desc[q[tt]] = i;
                tt--;
            }
            q[++tt] = i;
        }
        int res = 0;
        // for (int i = 1; i <= n; i++) {
        //     cout << asc[i] << " ";
        // }
        // puts("");
        // for (int i = 1; i <= n; i++) {
        //     cout << desc[i] << " ";
        // }
        for (int i = 1; i <= n; i++){
            int curmax = h[i] * (asc[i]-desc[i]-1);
            res = max(res, curmax);
        }
        return res;
    }
};