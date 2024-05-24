class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> hash;
        vector<string> res;
        for (int i = 0; i + 9 < s.size(); i++){
            string ss = s.substr(i, 10);
            if (hash[ss] == 1) {
                hash[ss] ++;
                res.push_back(ss);
            }else{
                hash[ss] ++;
            }
        }
        return res;
    }
};