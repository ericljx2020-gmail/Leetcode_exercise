class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        int n = time.size();

        long long l = 1, r = 1e18;
        while (l < r){
            long long mid = l + r >> 1;
            if (check(mid, time, totalTrips)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return r;
    }

    bool check(long long x, vector<int> time, int totalTrips){
        long long cur = 0;
        for (auto c : time){
            cur += x / c;
            if (cur >= totalTrips) return true;
        }
        return false;
    }
};