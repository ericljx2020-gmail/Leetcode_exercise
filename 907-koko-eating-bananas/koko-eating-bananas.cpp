class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxv = 0;
        for (auto c : piles){
            maxv = max(maxv, c);
        }
        int l = 1, r = maxv;
        while (l < r){
            int mid = l + r >> 1;
            if (check(mid, piles, h)) {
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return r;
    }

    bool check(int x, vector<int> piles, int h){
        int cur = 0;
        for (auto c : piles){
            cur += (c+x-1) / x;
            if (cur > h) return false;
        }
        return true;
    }
};