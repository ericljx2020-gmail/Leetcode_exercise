class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> stk;
        int res = 0;
        for (int i = 0, start = -1; i < n; i++){
            if (s[i] == '(') {
                stk.push(i);
            }else{
                if (stk.size()) {
                    stk.pop();
                    if (stk.size()){
                        res = max(res, i - stk.top());
                    }else{
                        res = max(res, i-start);
                    }
                }else{
                    //）是目前已经确定了不能匹配的右括号，所以下一个是下一个sequence的start
                    start = i;
                }
            }
        }
        return res;
    }
};