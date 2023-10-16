class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n, 0), s(n, 0), res(n,0);
        p[0] = nums[0];
        s[n-1] = nums[n-1];
        for (int i = 1; i < n; i++){
            p[i] = nums[i] * p[i-1];
        }
        for (int i = n-2; i >= 0; i--){
            s[i] = nums[i] * s[i+1];
        }
        res[0] = s[1];
        res[n-1] = p[n-2];
        for (int i = 1; i <= n-2; i++){
            res[i] = p[i-1] * s[i+1];
        }
        return res;
    }
};