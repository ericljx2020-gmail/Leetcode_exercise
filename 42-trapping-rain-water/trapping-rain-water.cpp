class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        vector<int> r(n,n), l(n,-1);
        int q[n+1];
        int tt = -1;
        for (int i = 0; i < n; i++){
            while (tt != -1 && a[q[tt]] <= a[i]){
                r[q[tt--]] = i;
            }
            q[++tt] = i;
        }
        tt = -1;
        for (int i = n-1; i >= 0; i--){
            while (tt != -1 && a[q[tt]] <= a[i]) {
                l[q[tt--]] = i;
            }
            q[++tt] = i;
        }
        // for (int i = 0; i < n; i++) cout << r[i] << " ";
        // puts("");
        // for (int i = 0; i < n; i++) cout << l[i] << " ";
        int res = 0;
        for (int i = 0; i < n; i++){
            if (r[i] != n){
                for (int j = i+1; j < r[i]; j++) {
                    res += max(0,a[i]-a[j]);
                    a[j] = a[i];
                }
            }
        }
        // cout << res << endl;
        for (int i = n-1; i >= 0; i--){
            if (l[i] != -1){
                for (int j = i-1; j > l[i]; j--){
                    res += max(0, a[i]-a[j]);
                    a[j] = a[i];
                }
            }
        }

        return res;
    }
};