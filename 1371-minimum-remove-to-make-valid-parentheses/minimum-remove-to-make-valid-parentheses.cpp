class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        string res = "";
        int n = s.size();
        unordered_map<int, bool> hash;
        for (int i = 0; i < n; i++) {
            if (s[i] == '('){
                stk.push(i);
            }else if (s[i] == ')'){
                if (stk.size()){
                    stk.pop();
                }else{
                    hash[i] = 1;
                }
            }
        }
        while (stk.size()){
            auto t = stk.top();
            stk.pop();

            hash[t] = 1;
        }

        for (int i = 0; i < n; i++){
            if (hash[i]) continue;
            res += s[i];
        }
        return res;
    }
};