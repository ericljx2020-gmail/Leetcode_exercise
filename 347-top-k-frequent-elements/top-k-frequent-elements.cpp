class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (auto c : nums){
            cnt[c]++;
        }
        vector<int> s(n+1, 0);
        for (auto [k,v]: cnt){
            s[v]++;
        }
        int i = n, t = 0;
        while (t < k){
            t += s[i--];
        }
        vector<int> res;
        for (auto [k,v] : cnt){
            if (v > i) res.push_back(k);
        }
        return res;
    }
};