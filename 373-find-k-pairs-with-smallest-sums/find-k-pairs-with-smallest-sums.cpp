typedef vector<int> VI;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (!nums1.size() || !nums2.size()) return {};
        int n = nums1.size(), m = nums2.size();
        priority_queue<VI, vector<VI>, greater<VI>> pq;

        for (int i = 0; i < m; i++) pq.push({nums1[0] + nums2[i], 0, i});

        vector<VI> res;
        while (k -- && pq.size()){
            VI t = pq.top();
            pq.pop();

            res.push_back({nums1[t[1]], nums2[t[2]]});
            if (t[1]+1 >= n) continue;
            pq.push({nums1[t[1]+1] + nums2[t[2]], t[1]+1, t[2]});
        }
        return res;
    }
};