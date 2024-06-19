class Solution {
public:
    const int N = 5e6+5;
    int countPrimes(int n) {
        bool is_prime[N];
        fill(is_prime, is_prime + N, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2;i*i<n; i++) 
        {                            
            if (is_prime[i])
            {
                for (int j = i*i;j<n; j += i)
                {
                    is_prime[j] = false;
                }
            }
        }
        int num=0;
        for (int i = 2;i<n; i++) 
            if(is_prime[i])
                 num++;
        return num;
    }
};