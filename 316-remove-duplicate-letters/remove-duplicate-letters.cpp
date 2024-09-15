class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> hash;
        for (auto c : s) hash[c]++;
        int n = s.size();
        string res = "";
        unordered_set<char> in_ans;
        for (int i = 0; i < n; i++){
            hash[s[i]]--;
            if (in_ans.find(s[i]) != in_ans.end()){
                continue;
            }
            while (res.size() && s[i] < res[res.size()-1] && hash[res[res.size()-1]] > 0){
                in_ans.erase(res[res.size()-1]);
                res = res.substr(0, res.size()-1);
            }
            res += s[i];
            in_ans.insert(s[i]);
        }
        return res;
    }
};