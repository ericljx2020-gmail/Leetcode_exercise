class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        // Move r left past any vals
        while (l <= r && nums[r] == val) r--;
        if (l > r) break;

        if (nums[l] == val) {
            swap(nums[l], nums[r]);
            // DO NOT l++ here; need to re-check the new nums[l]
        } else {
            l++;            // keep good element
        }
    }
    return l;               // first l elements are non-val
}

};