class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = digits.size();
        digits[l-1]++;
        for(int i=l-1;i>0;i--)
        {            
            if(digits[i] >= 10)
            {
                digits[i]-=10;
                digits[i-1]++;
            }
        }
        
        if(digits[0] >= 10)
        {
            digits[0] -= 10;
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};