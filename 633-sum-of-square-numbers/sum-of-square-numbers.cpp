class Solution {
public:
    vector<int> v;
    bool judgeSquareSum(int c) {
        const int T = INT_MAX;
        for (int i = 0; (long long)i * i < T; i++){
            v.push_back(i * i);
        }
        for (int i = 0; i < v.size(); i++){
            int r = find(c-v[i], 0, v.size()-1);
            if (v[r] == c-v[i]){
                return true;
            }
        }
        return false;
    }

    int find(int x, int l, int r){
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (v[mid] <= x){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        return r;
    }
};