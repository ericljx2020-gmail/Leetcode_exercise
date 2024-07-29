class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int l = 0, r = maxSum;
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (check(mid, n, index, (long long) maxSum)){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        // check(2, n, index, maxSum);
        return r;
    }

    bool check(int k, int n, int index, long long maxSum){
        int first = k-index;
        int f_left = 0;
        if (first < 1){
            f_left = 1-first;
        }
        first = max(first, 1);
        long long sum_f = (long long) (first + k) * (k-first+1) / 2;
        int rindex = n-index-1;
        int last = k-rindex;
        int r_left = 0;
        if (last < 1){
            r_left = 1-last;
        }
        last = max(last, 1);
        long long sum_r = (long long) (last + k) * (k-last+1) / 2;
        if (sum_r + sum_f - k + r_left + f_left > maxSum) return false;
        return true;
    }
};

// [2,3,4,5,6,7,8]