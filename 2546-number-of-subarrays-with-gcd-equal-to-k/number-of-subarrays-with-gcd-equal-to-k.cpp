class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int g = 0;
            //gcd只可能越变越小，因为前面的数字能够决定上限，所以只需要暴力枚举碰到一个gcd等于k的区间记录就可以
            for (int j = i; j < n; j++){
                g = __gcd(g, nums[j]);
                if (g % k != 0) break;
                if (g == k) res++;
            }
        }
        return res;
    }
};