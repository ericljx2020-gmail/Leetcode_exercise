class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res;
        res.push_back(1);
        for (int i = 0, j = 0, k = 0; res.size() < n; ){
            int t = min(res[i] * 2, min(res[j] * 3, res[k] * 5));
            if (t == res[i] * 2) i++;
            if (t == res[j] * 3) j++;
            if (t == res[k] * 5) k++;
            res.push_back(t);
        }
        return res[res.size()-1];
    }
};