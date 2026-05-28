class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) {
            right = right & (right - 1);
        }

        return right;
    }
};

==========



finding common prefix

it survives the &

and if no common prefix we get 0

[2, 100] => 0

=========
For any range [L, R]:

If L and R differ in binary prefix, the AND becomes 0 very quickly.

Because somewhere in the range, every bit position gets turned off at least once.


==========


left = 5, right = 8

right = 8 & 7  = 8  (1000 & 0111 = 0000... wait)
right = 8 & 7  = 0  ← jumps past left=5!

With !=  : 0 != 5, so loop continues → 0 & -1 = 0 → stuck ♾️
With <   : 0 < 5 is false → exits, returns 0 ✅ (correct answer)
