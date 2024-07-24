class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hash;
        int maxf = 0;
        int Mod = -1;
        for (auto c : nums){
            hash[c]++;
            if (hash[c] > maxf){
                maxf = hash[c];
                Mod = c;
            }
        }
        if (hash[Mod] * 2 > n) return hash[Mod] * 2 - n;
        if (hash[Mod] * 2 <= n && n & 1) return 1;
        return 0;
    }
};