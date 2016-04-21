class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0) return false;
        return num == pow(4, (int)(log(num) / log(4)));
    }
};
