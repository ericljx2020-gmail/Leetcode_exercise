class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-1; i++){
            int a = nums[i];
            int l_new = lower - a;
            int r_new = upper - a;
            int l = i+1, r = n-1;
            //找右端点
            while (l < r){
                int mid = l + r + 1 >> 1;
                if (nums[mid] <= r_new){
                    l = mid;
                }else{
                    r = mid-1;
                }
            }
            int rr = r;
            l = i+1, r = n-1;
            //找左端点
            while (l < r){
                int mid = l + r >> 1;
                if (nums[mid] >= l_new){
                    r = mid;
                }else{
                    l = mid+1;
                }
            }
            int ll = r;
            if (nums[ll] < l_new || nums[ll] > r_new || nums[rr] < l_new || nums[rr] > r_new) continue;
            res += rr-ll+1;
            // cout << ll << " " << rr << "\n";
        }
        return res;
    }
};


// 0 1 4 4 5 7