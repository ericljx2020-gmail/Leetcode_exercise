class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        vector<int> pre(n+5,0), suf(n+5, 0), res;
        pre[0] = 1;
        suf[n+1] = 1;
        for (int i = 1; i <= n; i++){
            pre[i] = pre[i-1] * nums[i];
        }

        for (int i = n; i >= 1; i --){
            suf[i] = suf[i+1] * nums[i];
        }

        for (int i = 1; i <= n; i++) cout << pre[i] << " ";
        puts("");
        for (int i = 1; i <= n; i++) cout << suf[i] << " ";
        for (int i = 1; i <= n; i++){
            res.push_back(pre[i-1] * suf[i+1]);
        }
        return res;
    }
};