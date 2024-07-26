class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n) return -1;
        int l = 1, r = 1e9;
        while (l < r){
            int mid = l + r >> 1;
            if (check(mid, bloomDay, m, k)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return r;
    }

    bool check(int x, vector<int> bloomDay, int m, int k){
        int cur = 0;            //current number of bonquet
        int n = bloomDay.size();
        int seqL = 0;
        for (int i = 0; i < n; i++){
            if (bloomDay[i] <= x){
                seqL++;
            }else{
                seqL = 0;
            }
            if (seqL == k) {
                cur++;
                seqL = 0;
            }
            if (cur >= m) return true;
        }
        return false;
    }
};