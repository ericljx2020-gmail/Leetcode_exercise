class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        for (int i = 0; i < f.size(); i++){
            if (i-1 >= 0 && f[i-1] == 0 && i+1 < f.size() && f[i+1] == 0){
                n -= (f[i] == 0);
                f[i] = 1;
            }else if(i == 0 && i+1 < f.size() && f[i+1] == 0){
                n -= (f[i] == 0);
                f[i] = 1;
            }else if (i == f.size()-1 && i-1 >= 0 && f[i-1] == 0){
                n -= (f[i] == 0);
                f[i] = 1;
            }else if (i == f.size()-1 && i == 0){
                n -= (f[i] == 0);
                f[i] = 1;
            }
        }
        // for (int i = 0; i < f.size(); i++) cout << f[i] << " ";
        return n<=0;
    }
};