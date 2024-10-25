class Solution {
public:

    static bool cmp(int a, int b) {return a > b;}

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash1;
        unordered_map<int, vector<int>> hash2;
        for(auto c : nums) hash1[c]++;
        vector<int>f;
        for (auto t : hash1) {
            hash2[t.second].push_back(t.first);
        }
        for (auto t : hash2){
            f.push_back(t.first);
        }
        sort(f.begin(), f.end(), cmp);
        int res = 0;
        vector<int> ans;
        for (int i = 0; i < f.size(); i++){
            for (auto c : hash2[f[i]]){
                ans.push_back(c);
                res++;
                if (res == k) return ans;
            }
        }
        return {};
    }
};