class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> stk;
        int res = 0;
        //维护一个从高到低的栈，每次新进来一个元素如果大于等于栈顶，处理完保证从i到stk.top之间的高度都是height[stk.top()]
        for (int i = 0; i < n; i++){
            int last = 0;
            while (stk.size() && height[stk.top()] <= height[i]){
                int j = stk.top();
                stk.pop();
                int h = height[j];
                res += (i-j-1) * (h-last);
                last = h;
            }
            if (stk.size()) res += (i-stk.top()-1) * (height[i] - last);
            stk.push(i);
        }
        return res;
    }
};