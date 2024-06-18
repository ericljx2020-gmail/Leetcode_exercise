class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> hash, st;
        for (auto c : nums){
            int mod = ((c % value) + value) % value;
            hash[mod]++;
        }
        for (int i = 0; i < value; i++){
            if (!hash[i]) return i;
            int cur = i;
            while (hash[i]){
                st[cur] = 1;
                hash[i]--;
                cur += value;
            }
        }
        for (int i = 0; true; i++){
            if (!st[i]) return i;
        }
        return nums.size();
    }
};