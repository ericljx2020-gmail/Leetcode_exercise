class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            nums.push_back(nums[i]);
        }
        stack<int> stk;
        vector<int> ans(n, -1);
        for (int i = 0; i < 2*n; i++){
            while (stk.size() && nums[i] > nums[stk.top()]){
                if (stk.top() < n) ans[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};