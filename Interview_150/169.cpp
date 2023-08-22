class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>hash;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            int c = nums[i];
            if (hash[c] == n / 2){
                return c;
            }
            hash[c] ++;
        }
        return 0;
    }
};