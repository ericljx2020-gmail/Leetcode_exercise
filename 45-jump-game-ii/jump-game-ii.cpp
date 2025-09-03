class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, INT_MAX);        // f[i]: minimum # step to jump to i
        f[0] = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if (j+nums[j] >= i) f[i] = min(f[i], f[j]+1);
            }
        }
        return f[n-1];

    }
};