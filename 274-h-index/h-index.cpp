class Solution {
public:
    bool check(int h, vector<int> citations) {
        int cnt = 0;
        for (auto c : citations) {
            if (c >= h) cnt++;
        }
        return cnt >= h;
    }
    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size();
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (check(mid, citations)){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        return r;
    }
};