class Solution {
public:
    int findComplement(int num) {
        int targetNumber = num;
        int bit = 1;
        
        while(targetNumber != 0)
        {
            num = num ^ bit;
            bit <<= 1;
            targetNumber >>= 1;
        }

        return num;
    }
};