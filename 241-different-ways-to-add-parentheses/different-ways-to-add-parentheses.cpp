class Solution {
public:
    vector<string> expr;
    vector<int> ans;
    vector<int> diffWaysToCompute(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++){
            if (isdigit(s[i])){
                int x = 0;
                int j = i;
                while (j < n && isdigit(s[j])) x = x * 10 + s[j++]-'0';
                i = j-1;
                expr.push_back(to_string(x));
            }else{
                expr.push_back(s.substr(i,1));
            }
        }    
        return dfs(0, expr.size()-1);
    }

    vector<int> dfs(int l, int r) {
        if (l == r) return {stoi(expr[l])};
        vector<int> res;
        for (int i = l+1; i < r; i+=2){
            auto left = dfs(l, i-1), right = dfs(i+1, r);
            for (auto c : left) {
                for (auto d : right){
                    int z;
                    if (expr[i] == "+") z = c + d;
                    else if (expr[i] == "-") z = c - d;
                    else z = c * d;
                    res.push_back(z);
                }
            }
        }
        return res;
    }
};