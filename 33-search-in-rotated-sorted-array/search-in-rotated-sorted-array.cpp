class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[0]){
                l = mid;
            }else{
                r = mid-1;
            }
        }

        if (target >= nums[0]){
            //in previous half
            l = 0;
        }else{
            l = r+1, r = nums.size() - 1;
        }

        while (l < r){
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        if (nums[r] == target){
            return r;
        }else{
            return -1;
        }
    }
};