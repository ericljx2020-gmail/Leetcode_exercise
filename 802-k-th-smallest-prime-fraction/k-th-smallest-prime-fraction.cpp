class Solution {
public:
    const double eps = 1e-8;
    int A,B;

    int get(vector<int> arr, double mid) {
        int res = 0;            //记录有多少个分数小于mid
        //双指针以后都可以用这个模版，比较清晰易懂
        for (int i = 0, j = 0; i < arr.size(); i++) {
            //对于每一个分母i，看有多少个j能够使得arr[j]/arr[i] <= mid
            
            //对于当前i，最大的分子是什么保证小于mid
            while ((double)arr[j+1] / arr[i] <= mid) j++;
            //判断一下是否小于mid，如果是的话从0-j个新的分数
            if ((double) arr[j] / arr[i] <= mid) res += j+1;
            //记录答案，如果找到一个分数和mid很接近，记录答案。
            //由于我们最后会找一次get(arr, r),这一次是一定会找到答案的，所以最后的A，B记录的就是答案的两个int
            if (fabs((double) arr[j] / arr[i] - mid) < eps){
                A = arr[j], B = arr[i];
            }
        }
        
        return res;
    }

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double l = 0, r = 1;
        //二分枚举double类型答案
        //对于每一个mid判断一下小于mid的分数数量是否大于k个，如果大于等于k说明mid这个分数肯定大于等于第k个由arr中组成的分数，因此我们可以往更小的枚举。
        while (l < r-eps) {
            double mid = (l+r) / 2;
            if (get(arr, mid) >= k) r = mid;
            else l = mid;
        }
        get(arr,r);
        return {A,B};
    }
};