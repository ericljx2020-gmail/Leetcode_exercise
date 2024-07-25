class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1e6;
        while (l < r){
            int mid = l + r >> 1;
            if (check(mid, nums, threshold)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return r;
    }

    bool check(int x, vector<int>& nums, int threshold){
        int sum = 0;
        for (auto c : nums){
            sum += (c + x - 1) / x;
            if (sum > threshold) return false;
        }
        return true;
    }
};