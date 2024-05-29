class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n);
        for (int i = 0; i < n; i++) p[i] = i;
        sort(p.begin(), p.end(), [&](int a, int b) {
            if (nums[a] != nums[b]) return nums[a] < nums[b];
            return a < b;
        });
        int res = 0;
        for (int j = 0, i = n; j < n; j++) {
            res = max(res, p[j]-i);
            i = min(i, p[j]);
        }
        return res;
    }
};