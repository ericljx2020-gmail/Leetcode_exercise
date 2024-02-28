class Solution {
public:
    bool isValid(string s) {
        char q[10005];
        int tt = -1;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                q[++tt] = s[i];
            }else{
                if (tt != -1 && s[i] == ')' && q[tt] =='('){
                    tt--;
                }else if (tt != -1 && s[i] == '}' && q[tt] == '{'){
                    tt--;
                }else if (tt != -1 && s[i] == ']' && q[tt] == '['){
                    tt--;
                }else{
                    return false;
                }
            }
        }
        if (tt == -1)return true;
        return false;
    }
};