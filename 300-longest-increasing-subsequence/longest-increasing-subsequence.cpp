class Solution {
public:
    static const int N = 2500;
    int lengthOfLIS(vector<int>& nums) {
        int f[N];
        int n = nums.size();
        for (int i = 0; i < n; i++) f[i] = 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if (nums[j] < nums[i]){
                    f[i] = max(f[i], f[j]+1);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++){
            res = max(res, f[i]);
        }
        return res;
    }
};