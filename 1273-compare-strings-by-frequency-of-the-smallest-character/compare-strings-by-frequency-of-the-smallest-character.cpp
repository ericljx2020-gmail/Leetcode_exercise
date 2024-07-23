class Solution {
public:

    int comp(string s){
        unordered_map<char, int> hash;
        char minv = 'z';
        for (auto c : s){
            hash[c]++;
            minv = min(minv, c);
        }
        return hash[minv];
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
         int n = queries.size();
         int m = words.size();
         vector<int> q, w, v;
         for (auto qe: queries) {
            int a = comp(qe);
            q.push_back(a);
            // cout << a << " ";
         }
        //  puts("");
         for (auto wd: words){
            int a = comp(wd);
            w.push_back(a);
            // cout << a << " ";
         }
         sort(w.begin(), w.end());
         for (int i = 0; i < n; i++){
            int t = q[i];
            int l = 0, r = m-1;
            while (l < r){
                int mid = l + r + 1 >> 1;
                if (w[mid] <= t){
                    l = mid;
                }else{
                    r = mid-1;
                }
            }
            if (r == m-1 && w[r] <= t) v.push_back(0);
            else if (r == m-1 && r == 0 && w[r] > t) v.push_back(1); 
            else v.push_back(m-r-1);
         }
         return v;
    }
};