class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        int bit=0;
        for(int i=0;i<32;i++){
            bit= n&1;
            ans<<=1;
            ans=ans|bit;
            
            n>>=1;
        }
            
        
        return ans;        
    }
};