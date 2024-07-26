class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxv = 0;
        for (auto c : weights) maxv = max(maxv, c);
        int l = maxv, r = 1e9+1;
        while (l < r){
            int mid = l + r >> 1;
            if (check(mid, weights, days)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return r;
    }

    bool check(int x, vector<int> w, int days){
        int cur = 0;
        int sum = 0;
        int n = w.size();
        for (int i = 0; i < n; i++){
            if (sum + w[i] > x){
                cur++;
                sum = 0;
            }
            sum += w[i];
            if (cur > days) return false;
        }
        if (sum) cur++;
        if (cur > days) return false;
        return true;
    }
};