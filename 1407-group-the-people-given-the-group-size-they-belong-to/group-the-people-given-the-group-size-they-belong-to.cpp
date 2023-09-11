class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> hash;
        vector<vector<int>> ans;
        int n = groupSizes.size();
        for (int i = 0; i < n; i++){
            int sz = groupSizes[i];
            hash[sz].push_back(i);
            if (hash[sz].size() == sz) {
                ans.push_back(hash[sz]);
                hash[sz].clear();
            }
        }
        return ans;
    }
};