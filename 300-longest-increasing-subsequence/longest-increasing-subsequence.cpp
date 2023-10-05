class Solution {
public:
    static const int N = 2500;
    int lengthOfLIS(vector<int>& nums) {
        int f[N];
        for (int i = 0; i < nums.size(); i++){
            f[i] = 1;
        }

        int n = nums.size();
        int res = 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if (nums[j] >= nums[i]) continue;
                f[i] = max(f[j]+1, f[i]);
                res = max(f[i], res);
            }
        }
        return res;
    }
};