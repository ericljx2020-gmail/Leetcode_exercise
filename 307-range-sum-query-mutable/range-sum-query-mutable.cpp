class NumArray {
public:
    vector<int> tree;
    vector<int> nums;
    int n;
    int prefix(int i) {
        int s = 0;
        for (;i>0; i -= i & -i){
            s += tree[i];
        }
        return s;
    }

    NumArray(vector<int>& _nums) {
        n = _nums.size();
        tree.resize(n+1,0);
        nums.resize(n,0);

        for (int i = 0; i < n; i++) update(i, _nums[i]);
    }
    
    void update(int idx, int val) {
        int delta = val - nums[idx];
        nums[idx] = val;
        for (int i = idx+1; i <= n; i += i & -i){
            tree[i] += delta;
            // cout << i << " " << tree[i] << " " << delta << "\n";
        }
        // puts("");
    }
    
    int sumRange(int left, int right) {
        return prefix(right+1) - prefix(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */