class Solution {
public:

    int quick_find(vector<int>& nums, int l, int r, int k){
        if (l == r) return nums[l];
        int x = nums[l+r >> 1], j = r + 1, i = l - 1;
        while (i < j){
            do i++; while (nums[i] > x);
            do j--; while (nums[j] < x);
            if (i < j) swap(nums[i], nums[j]);
        }

        if (j < k) return quick_find(nums, j+1, r, k);
        else return quick_find(nums, l, j, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quick_find(nums, 0, n-1 ,k-1);
    }
};