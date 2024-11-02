class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> stk;
        string s_copy = "";
        unordered_map<int, bool> st;
        for (int i = 0; i < n; i++){
            if (s[i] <= 'z' && s[i] >= 'a') continue;
            else if (s[i] == '(') stk.push(i);
            else{
                if (stk.empty()) st[i] = 1;             //不要
                else{
                    stk.pop();
                }
            }
        }
        while (stk.size()){
            int t = stk.top();
            st[t] = 1;
            stk.pop();
        }
        for (int i = 0; i < n; i++){
            if (st[i]) continue;
            s_copy += s[i];
        }
        return s_copy;
    }
};