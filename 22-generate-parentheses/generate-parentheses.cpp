class Solution {
public:
    string cur = "";
    vector<string> res;
    char p[2] = {'(', ')'};

    bool check(string s) {
        int l = 0;
        for (auto c : s){
            if (c == '('){
                l++;
            }else{
                l--;
                if (l < 0) return false;
            }
        }
        return l == 0;
    }

    void dfs(int x, int n){
        if(x == 2*n){
            if (check(cur)){
                res.push_back(cur);
            }
            return;
        }
        
        for (int i = 0; i < 2; i++){
            cur += p[i];
            dfs(x+1, n);
            cur = cur.substr(0, cur.size()-1);
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs(0, n);
        return res;
    }
};