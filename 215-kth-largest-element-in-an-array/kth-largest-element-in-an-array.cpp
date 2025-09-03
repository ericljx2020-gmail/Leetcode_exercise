class Solution {
public:
    int quick_find(vector<int> nums, int l, int r, int k) {
        if (l == r) return nums[l];
        int x = nums[l], i = l-1, j = r+1;
        while (i < j){
            do i++; while (nums[i] > x);
            do j--; while (nums[j] < x);
            if (i < j) swap(nums[i], nums[j]);
        }
        if (j < k) return quick_find(nums, j+1, r, k);
        return quick_find(nums, l,j,k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quick_find(nums, 0, nums.size()-1, k-1);
    }
};