class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        stack<int> stk;
        int n = nums.size();
        vector<int> rs(n, n), ls(n, -1);
        for (int i = 0; i < n; i++){
            while (stk.size() && nums[i] < nums[stk.top()]){
                rs[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while (stk.size()){
            stk.pop();
        }
        for (int i = n-1; i >= 0; i--){
            while (stk.size() && nums[i] < nums[stk.top()]){
                ls[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        int res = 0;
        for (int i = 0; i < n; i++){
            int l = ls[i], r = rs[i];
            // cout << i << " " << l << " " << r << "\n";
            if (l < k && r > k){
                res = max(res, (nums[i]) * (r-l-1));
            }
        }
        return res;
    }
};