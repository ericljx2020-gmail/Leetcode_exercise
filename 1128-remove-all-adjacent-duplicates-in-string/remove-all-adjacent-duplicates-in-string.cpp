class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for (auto c : s){
            if (stk.size() && stk.top() == c){
                stk.pop();
            }else{
                stk.push(c);
            }
        }
        string res = "";
        while (stk.size()){
            auto t = stk.top();
            stk.pop();
            res += t;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};