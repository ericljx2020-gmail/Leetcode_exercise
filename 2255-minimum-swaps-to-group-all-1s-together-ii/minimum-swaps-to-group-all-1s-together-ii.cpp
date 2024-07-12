class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = 0;
        for (auto c : nums){
            k += c;
        }
        int n = nums.size();
        for (int i = 0; i < n; i++){
            nums.push_back(nums[i]);
        }
        int q[1000000];
        int tt = -1, hh = 0;
        int cnt = 0;
        int maxv = 0;
        for (int i = 0; i < 2*n; i++){
            if (hh <= tt && q[hh] < i-k+1){
                cnt -= nums[q[hh++]];
            }
            q[++tt] = i;
            cnt += nums[i];
            if (i >= k-1){
                maxv = max(maxv, cnt);
            }
        }
        return k - maxv;
    }
};