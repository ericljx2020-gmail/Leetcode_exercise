class Solution {
public:
    vector<int> f;
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        s = ' ' + s;
        f.resize(n+1, 0);
        for (int i = 1; i <= n; i++){
            f[i] = f[i-1] + (s[i] == '|');
            cout << f[i] << ' ';
        }
        puts("");
        vector<int> res;
        for (auto q : queries){
            int l = q[0]+1, r = q[1]+1;
            int fl = s[l] == '|' ? l : find1(l, r, f[l])+1;
            int fr = s[r] == '|' ? r : find2(l, r, f[r]);
            // cout << fl << " " << fr << " ";  
            if (fl >= fr){
                res.push_back(0);
                continue;
            }
            int cnt = f[fr] - f[fl-1];
            // cout << cnt << "  " << fr-fl+1-cnt << '\n';
            res.push_back(fr-fl+1-cnt);
        }

        return res;
    }

    int find1(int l, int r, int x){
        //找第一个大于x的数
        while (l < r){
            int mid = l + r + 1 >> 1;
            if (f[mid] <= x){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        return r;
    }

    int find2(int l, int r, int x){
        //找第一个小雨x的数字
        while (l < r){
            int mid = l + r >> 1;
            if (f[mid] >= x){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return r;
    }

};