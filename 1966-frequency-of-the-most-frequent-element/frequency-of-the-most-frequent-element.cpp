class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.insert(nums.begin(), 0);
        vector<long long> f(n+1, 0);
        for (int i = 1; i <= n; i++) f[i] = f[i-1] + nums[i];
        int freq = 0;
        for (int i = 1, j = 1; i <= n; i++){
            while ((long long)(i-j+1) * nums[i] - (f[i] - f[j-1]) > k){
                j++;
            }
            freq = max(freq, i-j+1);
        }
        return freq;
    }
};