class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        for (int i = 0; i < n; i++){
            cardPoints.push_back(cardPoints[i]);
        }
        int q[1000000];
        long long res = 0;
        long long sum = 0;
        int tt = -1, hh = 0;
        for (int i = 0; i < 2*n; i++){
            if (hh <= tt && q[hh] < i-k+1){
                sum -= cardPoints[q[hh++]];
            }
            q[++tt] = i;
            sum += cardPoints[i];
            if (i >= k-1 && !((i < n-1 && i-k+1 > 0) || (i < 2*n-1 && i-k+1 > n))){
                res = max(res, sum);
            }
        }
        return res;
    }
};