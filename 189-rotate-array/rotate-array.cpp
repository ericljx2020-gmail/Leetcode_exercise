class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> hash;
        for (int i = 0; i < n; i++) {
            hash[i] = (i+k) % n;
        }
        vector<int> res(n,0);
        for(int i = 0; i < n; i++){
            res[hash[i]] = nums[i];
            // cout << hash[nums[i]] << " ";
        }
        nums = res;
        return;
    }
};