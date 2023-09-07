class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>Map;
        int l=0, r=0;
        bool isame = 0;
        for (int i = 0; i < nums.size(); i++){
            Map[nums[i]] += 1;
        }

        for (int i = 0; i < nums.size(); i++){
            int find = target - nums[i];    
            Map[nums[i]] -= 1;         
            if (Map[find] >= 1){
                l = i;
                r = find;
                break;
            }
            Map[nums[i]] += 1;
        }
        // cout << l << " " << r;
        for (int i = l+1; i < nums.size(); i++){
               if (nums[i] == r){
                   r = i;
                   break;
               }
        }
        vector<int>ans;
        ans.push_back(l);
        ans.push_back(r);
        return (ans);
    }
};