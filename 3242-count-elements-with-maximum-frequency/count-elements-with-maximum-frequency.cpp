class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> hash;
        int res = 0;
        for (auto c : nums) {
            hash[c]++;
            res = max(res, hash[c]);
        }
        int ans = 0;
        for (auto &[k,v] : hash){
            if (v == res){
                ans += v;
            }
        }
        return ans;
    }
};