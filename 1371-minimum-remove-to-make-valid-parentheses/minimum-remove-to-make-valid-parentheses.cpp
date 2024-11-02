class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<char> stk;
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (s[i] != ')'){
                stk.push(s[i]);
                if (s[i] == '(') cnt++;
            }else{
                if (cnt > 0) {
                    stk.push(s[i]);
                    cnt--;
                }
            }
        }
        string res = "";
        while(stk.size()){
            auto t = stk.top();
            stk.pop();
            if (t == '(' && cnt > 0){
                cnt--;
                continue;
            }
            res += t;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};