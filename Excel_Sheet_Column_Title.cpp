class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        do {
            n--;
            char c = 'A' + (char)(n % 26);
            ans = string(1, c) + ans;
            n/=26;
        } while(n);
        
        return ans;
    }
};
