class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        stack<int> stk;
        unordered_map<int, int> hash;
        vector<int> ans;
        for (int i = 0; i < m; i++){
            while (stk.size() && nums2[i] > nums2[stk.top()]) {
                hash[nums2[stk.top()]] = nums2[i];
                stk.pop();
            }
            stk.push(i);
        }
        while (stk.size()){
            hash[nums2[stk.top()]] = -1;
            stk.pop();
        }

        for (int i = 0; i < n; i++){
            ans.push_back(hash[nums1[i]]);
        }
        return ans;
    }
};