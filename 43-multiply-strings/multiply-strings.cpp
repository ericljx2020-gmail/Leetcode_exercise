class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> a, b;
        for (int i = num1.size()-1; i >= 0; i--) a.push_back(num1[i]-'0');
        for (int i = num2.size()-1; i >= 0; i--) b.push_back(num2[i]-'0');
        int n = a.size(), m = b.size();

        vector<int> C(n+m,0);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                C[i+j] += a[i] * b[j];
            }
        }

        for (int i = 0, t = 0; i < n+m; i++){
            t += C[i];
            C[i] = t % 10;
            t /= 10;
        }
        int t = C.size()-1;
        while (t > 0 && !C[t]){
            t--;
        }
        string res = "";
        while (t >= 0){
            res += C[t] + '0';
            t--;
        }
        return res;
        

    }
};