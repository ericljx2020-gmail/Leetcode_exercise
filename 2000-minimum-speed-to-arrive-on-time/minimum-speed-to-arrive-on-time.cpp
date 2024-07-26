class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = 1e7+1;
        while (l < r){
            int mid = l + r >> 1;
            if (check(mid, dist, hour)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        if (r != 1e7+1) return r;
        return -1;
    }

    bool check(int x, vector<int> dist, double hour){
        double cur = 0;
        for (auto c : dist){
            cur += (double) c / x;
            // cout << cur << " ";
            if (cur > hour) return false;
            cur = ceil(cur);
            // cout << cur << "\n";
        }
        // puts("");
        return true;
    }
};