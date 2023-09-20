class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = n - k % n;
        vector<int>ans;
        for (int i = k; i < n+k; i++){
            cout << i % n << endl;
            ans.push_back(nums[i % n]);
        }
        nums = ans;
        return ;
    }
};