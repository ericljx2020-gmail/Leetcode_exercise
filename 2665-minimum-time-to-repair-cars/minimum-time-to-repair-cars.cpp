class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, r = 1e18;
        while (l < r){
            long long mid = l + r >> 1;
            if (check(mid, ranks, cars)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return r;
    }

    bool check(long long x, vector<int> ranks, int cars) {
        long long cur = 0;
        for (auto c : ranks){
            long long nsquare = x / c;
            cur += floor(sqrt(nsquare));
            if (cur >= cars) return true;
        }
        return false;
    }
};