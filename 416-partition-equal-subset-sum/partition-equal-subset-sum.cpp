class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(20001, 0);
        int sum = 0;
        for (auto c : nums) sum += c;
        if (sum & 1) return false;
        f[0] = 1;
        for (int i = 0; i < n; i++){
            for (int j = 20000; j >= nums[i]; j--){
                f[j] = f[j] | f[j-nums[i]];
            }
        }
        
        return f[sum/2];
    }
};