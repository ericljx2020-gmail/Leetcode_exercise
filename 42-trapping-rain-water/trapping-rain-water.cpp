class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int>stk;
        int res = 0;
        for (int i = 0; i < n; i++){
            int last = 0;
            while (stk.size() && height[stk.top()] <= height[i]){
                res += (i-stk.top()-1) * (height[stk.top()] - last);
                last = height[stk.top()];
                stk.pop();
            }
            if (stk.size()) res += (i - stk.top()-1) * (height[i] - last);
            stk.push(i);
        }
        return res;
    }
};