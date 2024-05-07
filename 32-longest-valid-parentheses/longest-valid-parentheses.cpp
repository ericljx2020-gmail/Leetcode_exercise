class Solution {
public:
    /*
     * 思路：分段，保证每一段的 （ 数量小于 ）数量。
     */
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> stk;
        int res = 0;
        // ()((()...不关怎么加只要满足左括号数量小于右括号一定能够完全匹配，所以其实每一段的长度是确定的，加入右括号stk还不为空的情况是给结尾准备的
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