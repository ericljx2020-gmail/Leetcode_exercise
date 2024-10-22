class SparseVector {
public:
    vector<int> nums;
    SparseVector(vector<int> &nums) {
        this -> nums = nums;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for (int i = 0; i < vec.nums.size(); i++) res += vec.nums[i] * this -> nums[i];
        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);