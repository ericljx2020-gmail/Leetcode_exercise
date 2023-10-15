class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int n = s.size();
        int st = -1, l = 0;
        for (int i = 0; i < n; i++){
            if (st == -1 && s[i] == ' ') continue;
            if (st == -1 && s[i] != ' '){
                st = i;
                l = 1;
            }else if (st != -1 && s[i] != ' '){
                l++;
            }else if (st != -1 && s[i] == ' '){
                v.push_back(s.substr(st, l));
                st = -1;
            }
        }

        if (st != -1){
            v.push_back(s.substr(st, l));
        }
        string res = "";
        for (int i = v.size()-1; i >= 0; i--) {
            res += v[i];
            if (i != 0){
                res += " ";
            }
        }
        return res;
    }
};