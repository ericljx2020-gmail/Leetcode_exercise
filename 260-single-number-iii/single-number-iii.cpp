class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto c : nums){
            hash[c]++;
        }
        vector<int> v;
        for (auto c : nums){
            if (hash[c] == 1) v.push_back(c);
        }
        return v;
    }
};