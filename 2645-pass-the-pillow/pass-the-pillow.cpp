class Solution {
public:
    int passThePillow(int n, int time) {
        int d = 1;
        int p = 1;
        bool flag = false;
        while (time --){
            if (flag == true && (p == 1 || p == n)){
                d *= -1;
                // cout << time;
            }
            p += d;
            // cout << p << " ";
            flag = true;
        }
        return p;
    }
};