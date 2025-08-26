class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        vector<int> nxt;
        for (int i = n-k; i < 2*n-k; i++){
            nxt.push_back(nums[i%n]);
        }
        nums = nxt;
        return;
    }
};