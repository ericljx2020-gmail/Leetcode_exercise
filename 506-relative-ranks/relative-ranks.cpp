class Solution {
public:
    static bool cmp(int a, int b) {
        return a > b;
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> replicate;
        unordered_map<int, int> hash;
        for (int i = 0; i < score.size(); i++){
            replicate.push_back(score[i]);
        }
        sort(score.begin(), score.end(), cmp);
        for (int i = 0; i < score.size(); i++){ 
            hash[score[i]] = i+1;
        }
        vector<string> res;
        for (int i = 0; i < replicate.size(); i++){
            if (hash[replicate[i]] == 1) res.push_back("Gold Medal");
            else if (hash[replicate[i]] == 2) res.push_back("Silver Medal");
            else if (hash[replicate[i]] == 3) res.push_back("Bronze Medal");
            else{
                string s = to_string(hash[replicate[i]]);
                res.push_back(s);
            }
        }
        return res;
    }
};