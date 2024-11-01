class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> q1, q2;
        int res = 0;
        for (int i = 0, j = 0; i < n; i++){
            while (q1.size() && nums[i] >= nums[q1.back()]){
                q1.pop_back();
            }
            q1.push_back(i);
            while (q2.size() && nums[i] <= nums[q2.back()]){
                q2.pop_back();
            }
            q2.push_back(i);

            while (q1.size() && q2.size() && nums[q1.front()] - nums[q2.front()] > limit){
                if (j == q1.front()){
                    q1.pop_front();
                }
                if (j == q2.front()){
                    q2.pop_front();
                }
                j++;
            }
            res = max(res, i-j+1);
        }
        return res;
        
        return 0;
    }
};