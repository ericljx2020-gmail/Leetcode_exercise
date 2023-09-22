class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int l = 0, r = n-1;
        int res = 0;
        while (l < r){
            res = max(res, min(h[l], h[r]) * (r-l));
            if (h[r] <= h[l]) r--;
            else l++;
        }
        return res;
    }
};