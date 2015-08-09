// 0 minutes ago	Accepted	8 ms	cpp
class Solution {
public:
    bool isHappy(int n) {
        set<int> visited;
        while(n!=1) {
            visited.insert(n);
            n = getNext(n);
            if(visited.count(n)) return false;
        }
        return true;
    }
    
    int getNext(int n) {
        int c = 0;
        while(n>0) {
            int r = n%10;
            c += r*r;
            n/=10;
        }
        return c;
    }
};
