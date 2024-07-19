class Solution {
public:

    char df(char c){
        if (c <= 'z' && c >= 'a'){
            return 'A' + c-'a';
        }else{
            return 'a' + c - 'A';
        }
    }

    string longestNiceSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> hash;
        int res = 0;
        vector<string>v;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                string sub = s.substr(i, j-i+1);
                bool flag = true;
                hash.clear();
                for (int k = 0; k < sub.size(); k++){
                    hash[sub[k]] = 1;
                }
                for (int k = 0; k < sub.size(); k++){
                    if (hash[sub[k]] ^ hash[df(sub[k])]){
                        flag = false;
                    }
                }
                if (flag){
                    res = max(res, (int)sub.size());
                    v.push_back(sub);
                }
            }
        }
        for (auto ss : v){
            if (ss.size() == res) return ss;
        }
        return "";
    }
};