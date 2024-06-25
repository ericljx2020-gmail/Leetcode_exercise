class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<vector<int>> f(n+1, vector<int> (2, 0));
        unordered_map<int, int> hash, m;
        for (auto c : nums){
            hash[c] += c;
        }
        for (auto x : hash){
            m[x.second] = x.first;
        }
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        vector<int> v;
        v.push_back(0);
        for (int i = 1; i < nums.size(); i++){
            v.push_back(hash[nums[i]]);
            // cout << hash[nums[i]] << " ";
        }
        n = v.size()-1;
        for (int i = 1; i <= n; i++){
            f[i][0] = max(f[i-1][0], f[i-1][1]);
            f[i][1] = f[i-1][0] + v[i];
            // cout << m[v[i]] << " " << m[v[i-1]] << "\n";
            if (nums[i]-1 != nums[i-1]) f[i][1] = max(f[i][1], f[i-1][1] + v[i]);
            // cout << f[i][0] << " " << f[i][1] << "\n";
        }
        return max(f[n][0], f[n][1]);
        // return 0;
    }
};