class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        string s = "";
        string q[3005];
        int tt = -1;
        for (int i = 0; i < n; i++){
            if (path[i] == '/' || i == n-1){
                if (i == n-1 && path[i] != '/') s += path[i];
                if (s == ".."){
                    tt--;
                    tt = max(-1,tt);
                }else if (s == "." || s == ""){
                    s = "";
                    continue;
                }else{
                    q[++tt] = s;
                }
                s = "";
            }else{
                s += path[i];
            }
        }
        string res = "/";
        for (int i = 0; i <= tt; i++) {
            if (i != 0) res += '/';
            res += q[i];
        }
        return res;
    }
};