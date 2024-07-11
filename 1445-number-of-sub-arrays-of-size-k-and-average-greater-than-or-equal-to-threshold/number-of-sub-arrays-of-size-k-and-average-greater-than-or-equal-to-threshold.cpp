class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int tt = -1, hh = 0;
        int q[100000];
        int cnt = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++){
            if (hh <= tt && q[hh] < i-k+1){
                sum -= arr[q[hh++]];
            }
            q[++tt] = i;
            sum += arr[i];
            if (i >= k-1 && sum / k >= threshold){
                cnt++;
            }
        }
        return cnt;
    }
};