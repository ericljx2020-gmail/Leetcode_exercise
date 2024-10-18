class Solution {
public:
    vector<int> s;
    Solution(vector<int>& w) {
        s = w;
        for (int i = 1; i < s.size(); i++) s[i] += s[i-1];
    }
    
    int pickIndex() {
        int pick = rand() % s.back() + 1;           
        int l = 0, r = s.size()-1;
        while (l < r) {
            int mid = l + r >> 1;
            if (s[mid] >= pick){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */