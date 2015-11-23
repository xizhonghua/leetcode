class Solution {
public:
    string getHint(string secret, string guess) {
        int b = 0;
        int c = 0;
        for(int i=0;i<secret.length();++i) {
            if(secret[i] == guess[i]) {
                b++;
                guess[i] = 'X';
                secret[i] = 'O';
            }
        }
        
        for(int i=0;i<secret.length();++i)
            for(int j=0;j<guess.length();++j) {
                if(secret[i] == guess[j]) {
                    c++;
                    guess[j] = 'X';
                    secret[i] = 'O';
                }
            }
        
        stringstream ss;
        ss<<b<<'A'<<c<<'B';
        return ss.str();
    }
};
