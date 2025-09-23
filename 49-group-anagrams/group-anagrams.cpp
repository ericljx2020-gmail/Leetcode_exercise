class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto s : strs) {
            string cp = s;
            sort(cp.begin(), cp.end());
            hash[cp].push_back(s);
        }

        vector<vector<string>> res;
        for (auto &[k,v] : hash){
            res.push_back(v);
        }
        return res;
    }
};