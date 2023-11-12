class Solution {
public:
    string reverseWords(string s) {
        s = ' ' + s + ' ';
        int n = s.size();
        int l = 0, r = 1;
        vector<string> v;
        while (r < n){
            if (s[r] == ' '){
                if (r == l + 1){
                    //trivial
                    l = r;
                    r++;
                }else{
                    //non-trivial
                    v.push_back(s.substr(l+1, r-l-1));
                    l = r;
                    r++;
                }
            }else{
                r++;
            }
        }
        string res = "";
        for (int i = v.size()-1; i >= 0; i--){
            res += v[i];
            res += " ";
        }
        return res.substr(0,res.size()-1);
    }
};