class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> f(words.size(), vector<int> (26, 0));
        for (int i = 0; i < words.size(); i++){
            string w = words[i];
            for (auto c : w){
                f[i][c-'a']++;
            }
        }
        vector<string> res;
        for (char c='a'; c <= 'z'; c++){
            int minv = INT_MAX;
            for (int i = 0; i < words.size(); i++){
                minv = min(minv, f[i][c-'a']);
            }
            string s = "";
            s.push_back(c);
            for (int i = 0; i < minv; i++){
                res.push_back(s);
            }
        }
        return res;
    }
};