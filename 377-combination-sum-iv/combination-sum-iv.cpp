class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<unsigned> f(target+1, 0);
        f[0] = 1;
        for (int i = 1; i <= target; i++){
            for (auto c : nums){
                if (c <= i){
                    f[i] += f[i-c];
                }
            }
        }
        return f[target];
    }
};