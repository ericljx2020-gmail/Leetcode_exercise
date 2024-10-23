class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '('){
                stk.push(i);
            }else if (s[i] == ')'){
                if (stk.size() == 0) res++;
                else stk.pop();
            }
        }
        res += stk.size();
        return res;
    }
};