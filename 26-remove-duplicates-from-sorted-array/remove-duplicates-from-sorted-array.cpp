class Solution {
public:
    int removeDuplicates(vector<int>& all) {
        all.erase(unique(all.begin(), all.end()), all.end());
        return all.size();
    }
};