class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string cur = "";
        vector<string> words;
        for (auto c : s) {
            if (c == ' '){
                words.push_back(cur);
                cur = "";
            }else{
                cur += c;
            }
        } 
        words.push_back(cur);
        if (words.size() != pattern.size()) return false;
        unordered_map<char, string> hash;
        unordered_map<string, char> hs;
        for (int i = 0; i < pattern.size(); i++){
            auto c = pattern[i];
            if (hash.count(c) == 0 && hs.count(words[i]) == 0){
                hash[c] = words[i];
                hs[words[i]] = c;
            }else if (hash[c] != words[i] || hs[words[i]] != c) {
                cout << hash[c] << " " << words[i];
                return false;
            }
        }
        return true;
    }
};