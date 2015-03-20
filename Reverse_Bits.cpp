class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t mask1 = 1;
        uint32_t mask2 = 1<<31;
        uint32_t ans = 0;
        for(int i=0;i<32;i++)
        {
            if(n&mask1) ans |= mask2;
            mask1<<=1;
            mask2>>=1;
        }
        
        return ans;
    }
};
