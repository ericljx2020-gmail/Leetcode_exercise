class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int l1 = 1 * n, r1 = 6 * n, l2 = m * 1, r2 = m * 6;
        if (r1 < l2 || r2 < l1) return -1;      //没有交集
        int sum1 = 0, sum2 = 0;
        for (auto c : a) sum1 += c;
        for (auto c : b) sum2 += c;

        //如果sum1 >= sum2, 那么说明a要减，b要加，反之亦然
        if (sum1 < sum2){
            //让a一定大于b
            swap(a,b);
            swap(sum1, sum2);  
        }
        sort(a.begin(), a.end(), cmp);
        sort(b.begin(), b.end());
        int l = 0, r = 0;
        int diff = sum1 - sum2;
        int cnt = 0;
        // cout << diff;
        if (diff == 0) return 0;
        while (l < a.size() || r < b.size()){
            int sub = l == a.size() ? INT_MIN : a[l]-1;
            int add = r == b.size() ? INT_MAX : 6-b[r];
            if (sub >= add){
                diff -= sub;
                l++;
            }else{
                diff -= add;
                r++;
            }
            cnt++;
            if (diff <= 0){
                break;
            }
        }
        return cnt;
    }

    static bool cmp(int a, int b){
        return a > b;
    }
};