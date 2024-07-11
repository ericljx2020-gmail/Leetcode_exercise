class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> w;
        stack<char> p;
        w.push("");
        for (auto c : s){
            if (c == '('){
                p.push(c);
                w.push("");
            }else if (c == ')'){
                p.pop();
                string t = w.top();
                w.pop();
                if (w.empty()) w.push("");
                reverse(t.begin(), t.end());
                w.top() += t;
            }else{
                w.top() += c;
            }
        }
        return w.top();
    }
};