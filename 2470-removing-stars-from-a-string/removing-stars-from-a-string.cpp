class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        int n = s.size();
        for (int i = 0; i < n; i++){
            if (s[i] == '*'){
                stk.pop();
            }else{
                stk.push(s[i]);
            }
        }
        string res = "";
        while(stk.size()){
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};