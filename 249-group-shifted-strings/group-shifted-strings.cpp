class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        int n = strings.size();
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> res;
        for (auto c : strings) {
            int diff = c[0] - 'a';
            string cur = "";
            for (int i = 0; i < c.size(); i++){
                char t = (26+c[i]-diff) % 26;
                cur += t;
            }
            hash[cur].push_back(c);
        }

        for (auto [k,v] : hash){
            res.push_back(v);
        }
        return res;
    }
};