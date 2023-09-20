class Solution {
public:
    static bool cmp(int a, int b) {
        return a > b;
    }

    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end(), cmp);
        citations.insert(citations.begin(), 0);
        for (int i = 1; i <= n; i++){
            if (i > citations[i]) return i-1;
        }
        return n;
    }
};