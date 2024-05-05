class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        if (a.size() < 4) return {};
        int n = a.size();
        sort(a.begin(), a.end());
        vector<vector<int>>res;
        for (int i = 0; i < n; i++){
            if (i != 0 && a[i] == a[i-1]) continue;
            for (int j = i+1; j < n; j++){
                if (j != i+1 && a[j] == a[j-1]) continue;
                for (int k = j+1; k < n; k++){
                    if (k != j+1 && a[k] == a[k-1]) continue;
                    long long c = (long long)target - a[i] - a[j] - a[k];
                    if (c < a[k]) continue;             //c应该是在k-n之间，不可能比a[k]小
                    int p = find(c, k+1, n-1, a, n);
                    if (p < n) {
                        res.push_back({a[i],a[j],a[k],a[p]});
                        // cout << c << " ";
                    }
                }
            }
        }

        return res;
    }

    int find(long long t, int l, int r, vector<int> a, int n){
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (a[mid] <= t) l = mid;
            else r = mid-1;
        }
        if (r < l) return n;
        if (a[r] == t) {
            // cout << r << " ";
            return r;
        }
        else return n;
    }
};