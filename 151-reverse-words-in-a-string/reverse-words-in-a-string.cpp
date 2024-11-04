class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string cur = "";
        for (int i = 0; i < s.size(); i++){
            if (s[i] != ' ' && (i == 0 || s[i-1] == ' ')){
                //start of a string
                v.push_back(cur);
                cur = s[i];
            }else if (s[i] != ' '){
                cur += s[i];
            }
        }
        v.push_back(cur);
        reverse(v.begin(), v.end());
        string res = "";
        for (auto c : v) res += c + " ";
        return res.substr(0, res.size()-2);
    }
};