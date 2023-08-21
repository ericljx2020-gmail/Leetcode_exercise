class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        for (int i = 0; i < n; i++){
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = n-1, prel = -1, prer = -1;
            while (l < r){
                // cout << l << " " << r << endl;
                if (prel != -1 && nums[l] == nums[prel]){
                    l++;
                    continue;
                }else if (prer != -1 && nums[r] == nums[prer]){
                    r--;
                    continue;
                }
                if (nums[i] + nums[l] + nums[r] < 0){
                    prel = l;
                    l++;
                }else if (nums[i] + nums[l] + nums[r] > 0){
                    prer = r;
                    r--;
                }else{
                    vector<int>tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[l]);
                    tmp.push_back(nums[r]);
                    ans.push_back(tmp);
                    prel = l;
                    prer = r;
                    // cout << i << " " << l << " " << r << endl;
                    l++;
                    r--;
                }
            }
        }
        return ans;
    }
};


// -4 -1 -1 0 1 2