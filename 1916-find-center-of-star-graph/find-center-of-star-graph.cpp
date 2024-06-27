class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> in;
        for (auto edge : edges){
            in[edge[0]]++;
            in[edge[1]]++;
        }
        int n = in.size();
        for (auto c : in){
            if (c.second == n-1) return c.first;
        }
        return -1;
    }
};