class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, long long> hash;
        hash[0] = 1;
        long long res = 0;
        for (int i = 0; i < n; i++){
            res ^= nums[i];
            hash[res] ++;
        }
        long long ans = 0;
        for (auto t : hash){ 
            ans += (t.second * (t.second-1)) / 2;
            // cout << t.first << " " << t.second << "\n";
        }
        return ans;
    }
};