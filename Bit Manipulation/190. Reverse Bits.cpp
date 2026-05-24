class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        int pow = 31;
        
        for (int i = 0; i < 32; i++) {
            int bit = (n >> i) & 1;

            if (bit) ans += (1 << pow) - (pow == 31 ?  1 : 0); 
            --pow;
        }

        return ans;
    }
};

======

class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        
        
        for (int i = 0; i < 32; i++) {
            if ((n >> i) & 1) ans += (1 << (31 - i)) - ((31 - i) == 31 ?  1 : 0); 
        }

        return ans;
    }
};

=========

0  -   31
1  -   30
2  -   29
  .
  .
  .
  .
31 -   0

(k - 1) - i   <-- k - 1 is max
===== 
