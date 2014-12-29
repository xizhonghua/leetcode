class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> num;
        vector<int> fact(10, 1);
        for(int i=1;i<=9;i++) {
            num.push_back('0' + i);
            fact[i] = fact[i-1] * i;
        }
        
        string s;
        k--;
        while(n>0) {
            int d = k / fact[n-1];
            k %= fact[n-1];
            n--;
            s += num[d];
            for(int i=d;i<=8;i++)
                num[i] = num[i+1];
        }
        return s;
    }
};
