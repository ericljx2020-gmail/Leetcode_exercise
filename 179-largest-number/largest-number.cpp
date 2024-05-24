class Solution {
public:

    static bool cmp(string a, string b) {
        return a+b > b+a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> v;
        bool flag = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) flag = true;
            v.push_back(to_string(nums[i]));
        }
        if (!flag) return "0";
        sort(v.begin(), v.end(), cmp);
        string res = "";
        for (auto s : v) {
            // cout << s << " ";
            res += s;
        }
        return res;
    }
};