class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> stk;
        int remain = num.size()-k;

        for (int i = 0; i < num.size(); i++){
            int c = num[i] - '0';
            while (stk.size() && k && c < stk.top()){
                stk.pop();
                k--;
            }
            stk.push(c);
        }
        string s = "";
        while (stk.size()){
            int t = stk.top();
            stk.pop();

            s += to_string(t);
        }
        reverse(s.begin(), s.end());
        if (k) s = s.substr(0, remain);
        int i = 0;
        while (i < s.size()-1 && s[i] == '0') i++;
        s = s.substr(i);
        return s != "" ? s : "0";
    }
};