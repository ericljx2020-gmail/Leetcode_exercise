class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int q[500005];
        int tt = -1;
        int p[n+1], s[n+1];
        for (int i = 0; i < n; i++){
            while (tt != -1 && nums[i] > nums[q[tt]]){
                p[q[tt]] = i;
                tt--;
            }
            q[++tt] = i;
        }
        while (tt != -1){
            p[q[tt]] = -1;
            tt--;
        }
        tt = -1;
        for (int i = n-1; i >= 0; i--){
            while (tt != -1 && nums[i] < nums[q[tt]]){
                s[q[tt]] = i;
                tt--;
            }
            q[++tt] = i;
        }

        while (tt != -1){
            s[q[tt]] = -1;
            tt--;
        }

        // for (int i = 0; i < n; i++){
        //     cout << p[i] << " ";
        // }
        // puts("");
        // for (int i = 0; i < n; i++){
        //     cout << s[i] << " ";
        // }


        for (int i = 0; i < n; i++){
            if (p[i] != -1 && s[i] != -1){
                return true;
            }
        }

        return false;
    }
};