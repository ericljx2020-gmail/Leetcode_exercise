class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<int> f(n+1, 0);
        for (int i = 1; i <= n; i++){
            f[i] = f[i-1] + nums[i];
        }
        unordered_map<int, int> hash;
        for (int i = 1; i <= n; i++){
            f[i] = ((f[i] % k) + k) % k;
            // cout << f[i] << " ";
        }

        int res = 0;
        hash[0] = 1;
        for (int i = 1; i <= n; i++){
            if (hash[f[i]]){
                res += hash[f[i]];
            }
            hash[f[i]]++;
        }
        return res;
    }
};