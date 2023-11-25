class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<int> pre(n+1, 0);

        for (int i = 1; i <= n; i++){
            pre[i] = pre[i-1] + nums[i];
        }

        vector<int> res;
        for (int i = 1; i <= n; i++) {
            int l = 0, r = 0;
            if (i == 1){
                l = nums[i];
            }else{
                l = pre[i]-pre[0];
            }
            r = pre[n] - pre[i];
            int ai = (i * nums[i] - l) + (r - (n-i) * nums[i]);
            res.push_back(ai);
        }
        return res;
    }
};