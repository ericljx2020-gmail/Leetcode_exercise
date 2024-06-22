class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<int> f(n+1, 0);  //f[i] : there are f[i] number of odd number in range [0-i]
        for (int i = 1; i <= n; i++){
            f[i] = f[i-1] + (nums[i] & 1);
            cout << f[i] << " ";
        }

        unordered_map<int, int> hash;
        int res = 0;
        for (int i = 0; i <= n; i++){
            //f[i] number of odd, need f[i]-x = k, x = f[i] - k;
            res += hash[f[i] - k];
            hash[f[i]]++;
        }

        return res;
    }
};