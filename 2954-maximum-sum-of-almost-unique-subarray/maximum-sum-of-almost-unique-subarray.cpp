class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_set<int> st;
        unordered_map<int, int> hash;
        int n = nums.size();

        int q[100000];
        int tt = -1, hh = 0;
        long long sum = 0;
        long long res = 0;
        for (int i = 0; i < n; i++){
            if (hh <= tt && q[hh] < i-k+1){
                hash[nums[q[hh]]]--;
                if (hash[nums[q[hh]]] == 0){
                    st.erase(nums[q[hh]]);
                }
                sum -= nums[q[hh]];
                hh++;
            }
            q[++tt] = i;
            sum += nums[i];
            hash[nums[i]]++;
            if (hash[nums[i]] == 1){
                st.insert(nums[i]);
            }
            if (i >= k-1 && st.size() >= m){
                res = max(res, sum);
            }
        }
        return res;
    }
};