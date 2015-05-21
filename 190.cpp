class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t count = 0;
        uint32_t result = 0;
        while(count ++ < 32 )
        {
            result <<= 1;
            result |= (n&1);
            n >>=1;
        }
        return result;
    }
};