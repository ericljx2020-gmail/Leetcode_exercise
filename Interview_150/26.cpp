class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,bool>hash;
        for (int i = 0; i < nums.size(); i++){
            int c = nums[i];
            if (hash[c]){
                nums.erase(nums.begin() + i);
                i--;
            }else{
                hash[c] = true;
            }
        }
        return nums.size();
    }
};