class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<string> res;
        int n = nums.size();
        int st = nums[0];
        int cur = nums[0];
        for (int i = 1; i < n; i++){
            if (nums[i] != cur+1) {
                string c = to_string(st);
                string e = to_string(cur);
                string t;
                if (c != e){
                    t = c + "->" + e;
                }else{
                    t = c;
                }
                res.push_back(t);
                st = nums[i];
            }
            cur = nums[i];
        }
        if (st < cur){
            string c = to_string(st);
                string e = to_string(cur);
                string t = c + "->" + e;
                res.push_back(t);
        }else if (st == cur){
            res.push_back(to_string(cur));
        }
        return res;
    }
};