class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/"){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                if (t == "+") stk.push(b+a);
                else if (t == "-") stk.push(b-a);
                else if (t == "*") stk.push(a*b);
                else if (t == "/") stk.push(b/a);
            }else{
                stk.push(stoi(t));
            }
        }
        return stk.top();
    }
};