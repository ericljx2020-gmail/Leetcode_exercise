class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int minv = INT_MAX, maxv = INT_MIN;
        for (auto c : nums) {
            minv = min(minv, c);
            maxv = max(maxv, c);
            hash[c] ++;
        }

        for (int i = maxv; i >= minv; i--){
            k -= hash[i];
            if (k <= 0) return i;
        }
        return -1;
    }
};