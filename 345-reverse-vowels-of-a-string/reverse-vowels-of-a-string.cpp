class Solution {
public:
    string reverseVowels(string s) {
        vector<char>v;
        unordered_map<char, bool>hash;
        hash['a'] = 1;
        hash['e'] = 1;
        hash['i'] = 1;
        hash['o'] = 1;
        hash['u'] = 1;
        hash['A'] = 1;
        hash['E'] = 1;
        hash['I'] = 1;
        hash['O'] = 1;
        hash['U'] = 1;
        
        int n = s.size();
        for (int i = 0; i < n; i++){
            if (hash[s[i]]){
                v.push_back(s[i]);
                s[i] = '*';
            }
        }
        int idx = v.size()-1;
        for (int i = 0; i < n; i++){
            if (s[i] == '*'){
                s[i] = v[idx--];
            }
        }
        return s;
    }
};