class Solution {
public:

    int quicksort(vector<int> nums, int l, int r, int k){
        if (l == r) return nums[k];
        int x = nums[l], i = l-1, j = r+1;
        while (i < j){
            do i++; while (nums[i] > x);
            do j--; while (nums[j] < x);
            if (i < j) swap(nums[i], nums[j]);
        }
        if (k <= j) return quicksort(nums, l, j, k);
        else return quicksort(nums, j+1, r, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quicksort(nums, 0, nums.size()-1, k-1);
    }
};