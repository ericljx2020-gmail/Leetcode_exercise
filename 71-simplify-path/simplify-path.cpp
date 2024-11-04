class Solution {
public:
    string simplifyPath(string path) {
        string cur = "";
        int n = path.size();
        vector<string> dir;
        for (int i = 0; i < n; i++){
            if (path[i] == '/'){
                dir.push_back(cur);
                cur = "";
            }else{
                cur += path[i];
            }
        }
        dir.push_back(cur);
        stack<string> stk;
        for (auto d : dir) {
            if (d == ".."){
                if (stk.size())stk.pop();
            }else if (d != "." && d != ""){
                stk.push(d);
            }
        }
        vector<string> reversed_dir;

        string res = "/";
        while (stk.size()){
            reversed_dir.push_back(stk.top());
            stk.pop();
        }

        reverse(reversed_dir.begin(), reversed_dir.end());
        for (auto d : reversed_dir){
            res += d + '/';
        }
        return res == "/" ? res : res.substr(0, res.size()-1);
    }
};