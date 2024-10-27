class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> res;
        for (auto c : nums){
            if (c == lower){
                lower++;
            }else{
                res.push_back({lower, c-1});
                lower = c+1;
            }
        }
        if (lower <= upper){
            res.push_back({lower, upper});
        }
        return res;
    }
};