class Solution {
public:
    int addDigits(int num) {
        if(num<10) return num;
        return addDigits(addDigits(num%10) + addDigits(num/10));
    }
};
