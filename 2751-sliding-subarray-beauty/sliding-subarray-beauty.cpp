class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int q[1000000];
        int tt = -1, hh = 0;
        unordered_map<int, int> hash;
        vector<int> v;
        for (int i = 0; i < n; i++){
            if (hh <= tt && q[hh] < i-k+1){
                hash[nums[q[hh]]]--;
                hh++;
            }
            q[++tt] = i;
            hash[nums[i]]++;
            if (i >= k-1){
                int cnt = 0;
                int p = -1;
                bool flag = false;
                for (int j = -50; j <= 0; j++){
                    cnt += hash[j];
                    if (cnt >= x){
                        p = j;
                        flag = true;
                        break;
                    }
                }
                if (!flag){
                    v.push_back(0);
                }else{
                    v.push_back(p);
                }
            }
        }
        return v;
    }
};