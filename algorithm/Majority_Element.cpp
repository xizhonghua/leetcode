class Solution {
public:
    int majorityElement(vector<int> &num) {
        int n = num[0];
        int c = 1;
        const auto size = num.size();
        for(auto i=1u;i<size;++i) {
            if(n == num[i]) {
                c++;
            } else {
                c--;
                if(c==0) {
                    n = num[i];
                    c = 1;
                }
            }
        }
        return n;
    }
};
